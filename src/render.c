/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:04:22 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 14:50:44 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_floor(t_main_data *md)
{
	int	x;
	int	y;
	int	pix_addr;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			pix_addr = (y * md->wind.line_size) + (x * (md->wind.bpp / 8));
			md->wind.data[pix_addr] = md->conf.floor_color & 0xFF;
			md->wind.data[pix_addr + 1] = (md->conf.floor_color >> 8) & 0xFF;
			md->wind.data[pix_addr + 2] = (md->conf.floor_color >> 16) & 0xFF;
			if (md->wind.bpp == 32)
				md->wind.data[pix_addr + 3] = 0x00;
			x++;
		}
		y++;
	}
}

static void	draw_ceiling(t_main_data *md)
{
	int	x;
	int	y;
	int	pix_addr;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		x = 0;
		while (x < WIDTH)
		{
			pix_addr = (y * md->wind.line_size) + (x * (md->wind.bpp / 8));
			md->wind.data[pix_addr] = md->conf.ceiling_color & 0xFF;
			md->wind.data[pix_addr + 1] = (md->conf.ceiling_color >> 8) & 0xFF;
			md->wind.data[pix_addr + 2] = (md->conf.ceiling_color >> 16) & 0xFF;
			if (md->wind.bpp == 32)
				md->wind.data[pix_addr + 3] = 0x00;
			x++;
		}
		y++;
	}
}

unsigned int	color(int color[3])
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

void	render(int x, int y, t_main_data *md, int col)
{
	int	pix_addr;

	pix_addr = (y * md->wind.line_size) + (x * (md->wind.bpp / 8));
	md->wind.data[pix_addr] = col & 0xFF;
	md->wind.data[pix_addr + 1] = (col >> 8) & 0xFF;
	md->wind.data[pix_addr + 2] = (col >> 16) & 0xFF;
}

void	redisplay(t_main_data *md)
{
	mlx_destroy_image(md->wind.mlx, md->wind.img);
	md->wind.img = mlx_new_image(md->wind.mlx, WIDTH, HEIGHT);
	md->wind.data = mlx_get_data_addr(md->wind.img, &md->wind.bpp,
			&md->wind.line_size, &md->wind.endian);
	draw_ceiling(md);
	draw_floor(md);
	cast_rays(md);
	mlx_put_image_to_window(md->wind.mlx, md->wind.win, md->wind.img, 0, 0);
}
