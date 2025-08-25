/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:45:38 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 14:45:45 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	go_up(t_map *y, int x)
{
	if (y && y->cols[x] && y->cols[x] == '0')
		parse_path(y, x);
}

static void	go_down(t_map *y, int x)
{
	if (y && y->cols[x] && y->cols[x] == '0')
		parse_path(y, x);
}

static void	go_left(t_map *y, int x)
{
	if (x >= 0 && y && y->cols[x] == '0')
		parse_path(y, x);
}

static void	go_right(t_map *y, int x)
{
	if (x < y->num_cols - 1 && y && y->cols[x] == '0')
		parse_path(y, x);
}

void	parse_path(t_map *y, int x)
{
	if (y->cols[x] && y && y->cols[x] != ' ' && y->cols[x] != '1')
	{
		y->cols[x] = 'x';
		go_up(y->up, x);
		go_down(y->down, x);
		go_left(y, x - 1);
		go_right(y, x + 1);
	}
}
