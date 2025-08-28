/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:53:06 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/28 16:13:52 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_border(t_map *map)
{
	int		i;
	t_map	*temp;

	temp = map;
	while (temp)
	{
		i = 0;
		while (temp->cols[i])
		{
			if (temp->cols[i] == 'a')
				return (0);
			i++;
		}
		temp = temp->down;
	}
	return (1);
}

int	valid_walls(t_map *map)
{
	check_walls(map, 0);
	if (!valid_border(map))
		return (0);
	return (1);
}

static int	path(t_main_data *md)
{
	t_map	*y;
	int		x;
	char	player;

	if (!locate_player(md->map, &y, &x, &player))
		return (0);
	if (!player_pos(y, x))
		return (0);
	parse_path(y, x);
	y->cols[x] = player;
	md->position.orientation = player;
	md->position.row = y;
	md->position.col = x;
	while (y->up)
		y = y->up;
	if (no_path(y))
		return (0);
	return (1);
}

int	check_map(t_main_data *md)
{
	t_map	*temp;

	if (!valid_walls(md->map))
		return (0);
	if (!path(md))
		return (0);
	md->grid_cell[0] = WIDTH / md->map->num_cols;
	temp = md->map;
	while (temp->down)
		temp = temp->down;
	md->grid_cell[1] = HEIGHT / (temp->row_index);
	return (1);
}
