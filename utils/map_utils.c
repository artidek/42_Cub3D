/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:13:01 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/11 10:35:01 by aobshatk         ###   ########.fr       */
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
	else if ((!map->up && map->cols[i] == '0') || (!map->down && map->cols[i] == '0'))
		return (0);
	else if (map->up && map->up->cols[i] == ' ' && map->cols[i] == '0')
		return (0);
	else if (map->down && map->down->cols[i] == ' ' && map->cols[i] == '0')
		return (0);
	return (1);
}

int	check_row(char *row)
{
	int	i;
	int	j;
	char *symb;

	i = 0;
	symb = MAP_SYMB;
	while (row[i])
	{
		j = 0;
		while(symb[j])
		{
			if (row[i] == symb[j])
				break;
			j++;
		}
		if (!symb[j])
			return (0);
		i++;
	}
	return (1);
}
