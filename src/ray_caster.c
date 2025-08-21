/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:22:37 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/21 17:02:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int collision(float ray_x, float ray_y, t_main_data *md)
{
	int n_x;
	int n_y;

	n_x = (int)(ray_x /md->cell_size[1]);
	n_y = (int)(ray_y /md->cell_size[0]);
	if ( n_y >= 0 && n_x >= 0 && md->grid[n_y][n_x] == 1)
		return (1);
	return (0);
}

static float	distance(t_main_data *md, float	dx, float dy)
{
	float dist;
	float	angle;

	dist = sqrt((dx * dx) + dy * dy);
	angle = atan2(dy, dx) - md->position.pa;
	return (dist * cos(angle));
}

static void	start_drawing(t_main_data *md, float dist)
{
	float height;
	float start;
	float	end;

	height = (md->cell_size[1] / dist) * (WIDTH / 2);
	start = (HEIGHT - height) / 2;
	end = start + height;
	draw_object(md, start, end);
}

static void	move_ray(t_main_data *md)
{
	float	dist;

	if(cast_hor(md))
	{
		dist = distance(md, md->hx - md->position.x, md->hy - md->position.y);
		start_drawing(md, dist);
		return;
	}
	else if(cast_vert(md))
	{
		dist = distance(md, md->hx - md->position.x, md->hy - md->position.y);
		start_drawing(md, dist);
		return;
	}
	// while (!collision(ray_x, ray_y, md))
	// {
	// 	ray_x += cos(md->position.ra);
	// 	ray_y += sin(md->position.ra);
	// }
}

void	cast_rays(t_main_data *md)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		md->position.ra = md->position.pa - (FOV / 2) + (i * FOV / NUM_RAYS);
		move_ray(md);
		i++;
	}
}
