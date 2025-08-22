/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:48:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/22 10:55:24 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	orientation(int key_code, t_main_data *md)
{
	float	old_dir_x;
	float	oldplane_x;

	if (key_code == RIGHT)
	{
		old_dir_x = md->dir_x;
		md->dir_x = md->dir_x * cos(R_SPEED) - md->dir_y * sin(R_SPEED);
		md->dir_y = old_dir_x * sin(R_SPEED) + md->dir_y * cos(R_SPEED);
		oldplane_x = md->plane_x;
		md->plane_x = md->plane_x * cos(R_SPEED) - md->plane_y * sin(R_SPEED);
		md->plane_y = oldplane_x * sin(R_SPEED) + md->plane_y * cos(R_SPEED);
	}
	if (key_code == LEFT)
	{
		old_dir_x = md->dir_x;
		md->dir_x = md->dir_x * cos(-R_SPEED) - md->dir_y * sin(-R_SPEED);
		md->dir_y = old_dir_x * sin(-R_SPEED) + md->dir_y * cos(-R_SPEED);
		oldplane_x = md->plane_x;
		md->plane_x = md->plane_x * cos(-R_SPEED) - md->plane_y * sin(-R_SPEED);
		md->plane_y = oldplane_x * sin(-R_SPEED) + md->plane_y * cos(-R_SPEED);
	}
}

static void	set_east_west(t_main_data *md)
{
	if (md->position.orientation == 'E')
	{
		md->dir_x = 1;
		md->dir_y = 0;
		md->plane_x = 0;
		md->plane_y = 0.66;
	}
	else if (md->position.orientation == 'W')
	{
		md->dir_x = -1;
		md->dir_y = 0;
		md->plane_x = 0;
		md->plane_y = -0.66;
	}
}

void	set_initial_orientation(t_main_data *md)
{
	if (md->position.orientation == 'N')
	{
		md->dir_x = 0;
		md->dir_y = -1;
		md->plane_x = 0.66;
		md->plane_y = 0;
	}
	else if (md->position.orientation == 'S')
	{
		md->dir_x = 0;
		md->dir_y = 1;
		md->plane_x = -0.66;
		md->plane_y = 0;
	}
	set_east_west(md);
}
