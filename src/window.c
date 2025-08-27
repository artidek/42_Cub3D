/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:08:54 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 14:51:15 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_keys(int key_code, t_main_data *md)
{
	if (key_code == 65307)
		mlx_loop_end(md->wind.mlx);
	else if (key_code == A || key_code == S || key_code == W || key_code == D)
	{
		move(key_code, md);
		redisplay(md);
	}
	else if (key_code == LEFT || key_code == RIGHT)
	{
		orientation(key_code, md);
		redisplay(md);
	}
	return (0);
}

static int	close_msg(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	start_window(t_main_data *md)
{
	md->wind.mlx = mlx_init();
	if (!md->wind.mlx)
		return (0);
	md->wind.win = mlx_new_window(md->wind.mlx, WIDTH, HEIGHT, "cub3d");
	md->wind.img = mlx_new_image(md->wind.mlx, WIDTH, HEIGHT);
	md->wind.data = mlx_get_data_addr(md->wind.img, &md->wind.bpp,
			&md->wind.line_size, &md->wind.endian);
	get_grid_coord(md);
	set_initial_orientation(md);
	redisplay(md);
	mlx_hook(md->wind.win, 2, 1L << 0, get_keys, md);
	mlx_hook(md->wind.win, 33, 0, close_msg, md->wind.mlx);
	mlx_loop(md->wind.mlx);
	return (1);
}
