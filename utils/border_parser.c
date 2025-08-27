/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:18:42 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 16:31:20 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_down(t_map *map, int i);
static void	check_right(t_map *map, int i);
static void	check_left(t_map *map, int i);

static void	check_up(t_map *map, int i)
{
	if (map->up && i <= map->up->num_cols - 2)
	{
		if ((map->up->cols[i] == ' ' || map->up->cols[i] == '	')
			&& map->cols[i] == '0')
			map->cols[i] = 'a';
	}
	if (!map->up && i < map->num_cols - 2 && map->cols[i] == '0')
		map->cols[i] = 'a';
	check_down(map, i);
}

static void	check_down(t_map *map, int i)
{
	if (map->down && i < map->down->num_cols - 2)
	{
		if ((map->down->cols[i] == ' ' || map->down->cols[i] == '	')
			&& map->cols[i] == '0')
			map->cols[i] = 'a';
	}
	if (!map->down && i < map->num_cols - 2 && map->cols[i] == '0')
		map->cols[i] = 'a';
	check_right(map, i);
}

static void	check_right(t_map *map, int i)
{
	if (i < map->num_cols - 2)
	{
		if ((map->cols[i + 1] == ' ' || map->cols[i + 1] == '	')
			&& map->cols[i] == '0')
		{
			map->cols[i] = 'a';
		}
		else
		{
			check_left(map, i);
			check_up(map, i + 1);
		}
	}
	if (i == map->num_cols - 2 && map->cols[i + 1] == '0')
		map->cols[i] = 'a';
	if (i == map->num_cols - 3)
	{
		check_walls(map->down, 0);
	}
}

static void	check_left(t_map *map, int i)
{
	if (i > 0)
	{
		if ((map->cols[i - 1] == ' ' || map->cols[i - 1] == '	')
			&& map->cols[i] == '0')
			map->cols[i] = 'a';
	}
	if (i == 0 && map->cols[i] == 'a')
		map->cols[i] = 'a';
}

void	check_walls(t_map *map, int i)
{
	if (map)
		check_up(map, i);
}
