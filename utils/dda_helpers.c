/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:52:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/22 10:06:36 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void get_grid_coord(t_main_data *md)
{
	md->pos_x = md->position.col;
	md->pos_y = md->position.row->row_index;
}

void get_delta_dist(t_main_data *md)
{
	if (md->ray_dirx == 0)
		md->delta_dist_x = 1e30;
	else
		md->delta_dist_x = fabs(1 / md->ray_dirx);
	if (md->ray_diry == 0)
		md->delta_dist_y = 1e30;
	else
		md->delta_dist_y = fabs(1/ md->ray_diry);
}

int	collision(float ray_x, float ray_y, t_main_data *md)
{
	int	n_x;
	int	n_y;

	n_x = (int)ray_x / md->cell_size[1];
	n_y = (int)ray_y / md->cell_size[0];
	if (n_y >= 0 && n_x >= 0 && n_x < md->grid_size[1] && n_y < md->grid_size[0]
		&& md->grid[n_y][n_x] == 1)
		return (1);
	return (0);
}