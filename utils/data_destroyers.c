/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroyers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:52:19 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/10 19:38:37 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_main_data(t_main_data *md)
{
	int	i;

	i = 0;
	while(i < 4)
	{
		if (md->conf.textures[i].text_arr)
			free_int_arr(md->conf.textures[i].text_arr, md->conf.textures[i].height);
		i++;
	}
	if (md->map)
		free_map(md->map);
	free(md->pwd);
}

void	free_int_arr(int **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	t_map *temp;

	while (map)
	{
		temp = map->down;
		free(map->cols);
		free(map);
		map = temp;
	}
}