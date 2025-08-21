/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:54:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/21 17:06:39 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int is_grid_coord(t_main_data *md)
{
    int gx = (int)(md->hx / md->cell_size[0]);
    int gy = (int)(md->hy / md->cell_size[0]);

    if (gx >= 0 && gy >= 0 && gx < md->grid_size[1] && gy < md->grid_size[0])
        return 1;
    return 0;
}

static void	move_ray(t_main_data *md, int hor)
{
	while(is_grid_coord(md))
	{
		if (!hor)
			printf("x %f y %f\n", md->hx, md->hy);
		if (collision(md->hx, md->hy, md))
		{
			if (hor)
				md->hor = 1;
			else
				md->vert = 1;
			return;
		}
		md->hx += md->xo;
		md->hy += md->yo;
	}
}

int cast_hor(t_main_data *md)
{
    md->hor = 0;
    float ra = md->position.ra;
    float px = md->position.x;
    float py = md->position.y;
    float cell = md->grid_cell[0];

    if (fabs(sin(ra)) < 1e-6) // ray almost horizontal
        return 0;

    if (sin(ra) > 0) { // facing down
        md->hy = floor(py / cell) * cell + cell;
        md->yo = cell;
    } else {           // facing up
        md->hy = floor(py / cell) * cell - 0.0001;
        md->yo = -cell;
    }
    md->hx = px + (md->hy - py) / tan(ra);
    md->xo = md->yo / tan(ra);

    move_ray(md, 1);
    return md->hor;
}

int cast_vert(t_main_data *md)
{
    md->vert = 0;
    float ra = md->position.ra;
    float px = md->position.x;
    float py = md->position.y;
    float cell = md->grid_cell[0];

    if (fabs(cos(ra)) < 1e-6) // ray almost vertical
        return 0;

    if (cos(ra) > 0) { // facing right
        md->hx = floor(px / cell) * cell + cell;
        md->xo = cell;
    } else {           // facing left
        md->hx = floor(px / cell) * cell - 0.0001;
        md->xo = -cell;
    }
    md->hy = py + (md->hx - px) * tan(ra);
    md->yo = md->xo * tan(ra);
    move_ray(md, 0);
    return md->vert;
}

