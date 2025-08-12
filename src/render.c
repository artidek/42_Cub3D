/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:04:22 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:43 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	render(int x, int y, t_main_data *md, char type)
{
	unsigned int	rgb;
	int	pix_addr;

	pix_addr = (y * md->wind.line_size) + (x * (md->wind.bpp/8));
	if (type == 'P')
		rgb = color(md->conf.ceiling_color[0], md->conf.ceiling_color[1], md->conf.ceiling_color[2]);
	if (type == 'W')
		rgb = color(md->conf.floor_color[0], md->conf.floor_color[1], md->conf.floor_color[2]);
	md->wind.data[pix_addr] = rgb & 0xFF;
	md->wind.data[pix_addr + 1] = (rgb >> 8) & 0xFF;
	md->wind.data[pix_addr + 2] = (rgb >> 16) & 0xFF;
	if (md->wind.bpp == 32)
		md->wind.data[pix_addr + 3] = 0x00; 
}

void	redisplay(t_main_data *md)
{
	mlx_destroy_image(md->wind.mlx, md->wind.img);
	md->wind.img = mlx_new_image(md->wind.mlx, WIDTH, HEIGHT);
	md->wind.data = mlx_get_data_addr(md->wind.img, &md->wind.bpp, &md->wind.line_size, &md->wind.endian);
	draw_map(md);
	mlx_put_image_to_window(md->wind.mlx, md->wind.win, md->wind.img,0,0);
}