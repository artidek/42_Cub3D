/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:13:01 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/11 13:36:13 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_border(t_map *map, int i)
{
	if (i > 0 && map->cols[i - 1] == ' ' && map->cols[i] == '0')
		return (0);
	else if (i == 0 && map->cols[i] == '0')
		return (0);
	else if (map->cols[i + 1] && map->cols[i] == '0' && map->cols[i + 1] == ' ')
		return (0);
	else if (!map->cols[i + 1] && map->cols[i] == '0')
		return (0);
	else if ((!map->up && map->cols[i] == '0') || (!map->down
			&& map->cols[i] == '0'))
		return (0);
	else if (map->up && map->up->cols[i] && map->cols[i]
		&& map->up->cols[i] == ' ' && map->cols[i] == '0')
		return (0);
	else if (map->down && map->down->cols[i] && map->cols[i]
		&& map->down->cols[i] == ' ' && map->cols[i] == '0')
		return (0);
	return (1);
}

int	check_row(char *row)
{
	int		i;
	int		j;
	char	*symb;

	i = 0;
	symb = MAP_SYMB;
	while (row[i])
	{
		j = 0;
		while (symb[j])
		{
			if (row[i] == symb[j])
				break ;
			j++;
		}
		if (!symb[j])
			return (0);
		i++;
	}
	return (1);
}

int	locate_player(t_map *map, t_map **y, int *x, char *player)
{
	int	i;
	int	count;

	count = 0;
	while (map)
	{
		i = 0;
		while (map->cols[i])
		{
			if (map->cols[i] == MAP_SYMB[0] || map->cols[i] == MAP_SYMB[1]
				|| map->cols[i] == MAP_SYMB[2] || map->cols[i] == MAP_SYMB[3])
			{
				count++;
				*y = map;
				*x = i;
				*player = map->cols[i];
			}
			i++;
		}
		map = map->down;
	}
	if (count == 0 || count > 1)
		return (0);
	return (1);
}

int	no_path(t_map *y)
{
	int i;

	while(y)
	{
		i = 0;
		while (y->cols[i])
		{
			if (y->cols[i] == '0')
				return (1);
			i++;
		}
		y = y->down;
	}
	return (0);
}