/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:04:22 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/18 23:06:09 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	color(int color[3])
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

void	render(int x, int y, t_main_data *md, int col[3])
{
	unsigned int	rgb;
	int	pix_addr;

	pix_addr = (y * md->wind.line_size) + (x * (md->wind.bpp/8));
	rgb = color(col);
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
	//draw_map(md);
	cast_rays(md);
	mlx_put_image_to_window(md->wind.mlx, md->wind.win, md->wind.img,0,0);
}
