/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:22:37 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 14:51:57 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw(t_main_data *md)
{
	md->line_height = (int)(HEIGHT / md->perp_wall_dist);
	md->draw_start = -md->line_height / 2 + HEIGHT / 2;
	if (md->draw_start < 0)
		md->draw_start = 0;
	md->draw_end = md->line_height / 2 + HEIGHT / 2;
	if (md->draw_end > HEIGHT)
		md->draw_end = HEIGHT - 1;
	draw_object(md);
}

static void	distance(t_main_data *md)
{
	if (md->side == 0)
		md->perp_wall_dist = md->side_dist_x - md->delta_dist_x;
	else
		md->perp_wall_dist = md->sidi_dist_y - md->delta_dist_y;
	draw(md);
}

static void	move_ray(t_main_data *md)
{
	while (md->hit == 0)
	{
		if (md->side_dist_x < md->sidi_dist_y)
		{
			md->side_dist_x += md->delta_dist_x;
			md->map_x += md->step_x;
			md->side = 0;
		}
		else
		{
			md->sidi_dist_y += md->delta_dist_y;
			md->map_y += md->step_y;
			md->side = 1;
		}
		if (md->grid[md->map_y][md->map_x] == 1)
			md->hit = 1;
	}
	distance(md);
}

static void	set_ray(t_main_data *md)
{
	md->map_x = (int)md->pos_x;
	md->map_y = (int)md->pos_y;
	md->hit = 0;
	get_delta_dist(md);
	if (md->ray_dirx < 0)
	{
		md->step_x = -1;
		md->side_dist_x = (md->pos_x - md->map_x) * md->delta_dist_x;
	}
	else
	{
		md->step_x = 1;
		md->side_dist_x = (md->map_x + 1.0 - md->pos_x) * md->delta_dist_x;
	}
	if (md->ray_diry < 0)
	{
		md->step_y = -1;
		md->sidi_dist_y = (md->pos_y - md->map_y) * md->delta_dist_y;
	}
	else
	{
		md->step_y = 1;
		md->sidi_dist_y = (md->map_y + 1.0 - md->pos_y) * md->delta_dist_y;
	}
	move_ray(md);
}

void	cast_rays(t_main_data *md)
{
	int	x;

	x = 0;
	md->tex_x = 0;
	md->tex_y = 0;
	md->position.wall_x = 0;
	while (x < WIDTH)
	{
		md->camera_x = 2 * x / (double)WIDTH - 1;
		md->ray_dirx = md->dir_x + md->plane_x * md->camera_x;
		md->ray_diry = md->dir_y + md->plane_y * md->camera_x;
		set_ray(md);
		x++;
	}
}
