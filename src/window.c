/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:08:54 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/11 20:18:37 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	keys(int key_code, t_main_data *md)
{
	if (key_code == 65307)
		mlx_loop_end(md->wind.mlx);
	//render(key_code, md);
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
	md->wind.win = mlx_new_window(md->wind.mlx, HEIGHT, WIDTH, "cub3d");
	md->wind.img = mlx_new_image(md->wind.mlx, HEIGHT, WIDTH);
	mlx_key_hook(md->wind.win, keys, md->wind.mlx);
	mlx_hook(md->wind.win, 33, 0, close_msg, md->wind.mlx);
	mlx_loop(md->wind.mlx);
	return (1);
}