/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:13:01 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/10 19:20:42 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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