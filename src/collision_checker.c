/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:17:42 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/13 20:04:47 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	front_collision(t_main_data *md, float c_y)
{
	t_map	*temp;

	if (c_y < md->grid_cell[1] * md->position.row->row_index)
	{
		temp = md->position.row->up;
		if (temp->cols[md->position.col] == '1')
		{
			md->front_col = 1;
			md->position.y = md->position.row->row_index * md->grid_cell[1] + 2;
			return (1);
		}
	}
	md->position.y = c_y;
	return (0);
}

int	back_collision(t_main_data *md, float c_y)
{
	t_map	*temp;

	if (c_y >= md->grid_cell[1] * md->position.row->row_index)
	{
		temp = md->position.row->down;
		if (temp->cols[md->position.col] == '1')
		{
			md->back_col = 1;
			md->position.y = md->position.row->row_index * md->grid_cell[1] + 2;
			return (1);
		}
	}
	md->position.y = c_y;
	return (0);
}

int	left_collision(t_main_data *md, float c_x)
{
	char	cell;

	cell = '0';
	if (md->position.col - 1 > 0)
		cell = md->position.row->cols[md->position.col - 1];
	if (c_x < md->grid_cell[0] * md->position.col && cell == '1')
	{
		md->position.x = md->position.col * md->grid_cell[0];
		return (1);
	}
	md->position.x = c_x;
	return (0);
}

int	right_collision(t_main_data *md, float c_x)
{
	char cell;

	cell = '0';
	if (md->position.row->cols[md->position.col + 1])
		cell = md->position.row->cols[md->position.col + 1];
	if (c_x > md->grid_cell[0] * md->position.col && cell == '1')
	{
		md->position.x = md->position.col * md->grid_cell[0];
		return (1);
	}
	md->position.x = c_x;
	return (0);
}