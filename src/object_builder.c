/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/22 23:56:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_texture(t_main_data *md)
{
	if (md->side == 0)
	{
		if (md->ray_dirx > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (md->ray_diry > 0)
			return (SO);
		else
			return (NO);
	}
}

static void	set_pos(t_main_data *md)
{
	double	wall_x;

	if (md->side == 0)
		wall_x = md->pos_y + md->perp_wall_dist * md->ray_diry;
	else
		wall_x = md->pos_x + md->perp_wall_dist * md->ray_dirx;
	wall_x -= floor(wall_x);
	md->tex_x = (int)(wall_x * (double)md->conf.textures[NO].width);
	if (md->side == 0 && md->ray_dirx > 0)
		md->tex_x = md->conf.textures[NO].width - md->tex_x - 1;
	if (md->side == 1 && md->ray_dirx < 0)
		md->tex_x = md->conf.textures[NO].width - md->tex_x - 1;
}

void	draw_object(t_main_data *md)
{
	double	step;
	double	tex_pos;
	int		color;
	int		texture;

	set_pos(md);
	step = 1.0 * md->conf.textures[NO].height / md->line_height;
	tex_pos = (md->draw_start - HEIGHT / 2 + md->line_height / 2) * step;
	while (md->draw_start < md->draw_end)
	{
		md->tex_y = (int)tex_pos & (md->conf.textures[NO].height - 1);
		tex_pos += step;
		texture = get_texture(md);
		color = md->conf.textures[texture].text_arr[md->conf.textures[texture].width
			* md->tex_y + md->tex_x];
		if (md->side == 1)
			color = (color >> 1) & 8355711;
		render(md->position.wall_x, md->draw_start, md, color);
		md->draw_start += 1;
	}
	md->position.wall_x += 1;
}
