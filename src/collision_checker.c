/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:50:40 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/18 14:02:20 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	forward_collision(t_main_data *md, float dy)
{
	t_map	*temp;

	if (dy < md->grid_cell[1] * md->position.row->row_index)
	{
		temp = md->position.row->up;
		if (temp->cols[md->position.col] == '1')
		{
			md->position.y = md->grid_cell[1] * md->position.row->row_index;
			return ;
		}
		md->position.row = temp;
	}
	md->position.y = dy;
}

void	backward_collision(t_main_data *md, float dy)
{
	t_map	*temp;

	if (dy > md->grid_cell[1] * md->position.row->row_index)
	{
		temp = md->position.row->down;
		if (temp->cols[md->position.col] == '1')
		{
			md->position.y = md->grid_cell[1] * md->position.row->row_index;
			return ;
		}
		md->position.row = temp;
	}
	md->position.y = dy;
}

void	left_collision(t_main_data *md, float dx)
{
	char	temp;

	if (dx < md->grid_cell[0] * md->position.col)
	{
		temp = md->position.row->cols[md->position.col - 1];
		if (temp == '1')
		{
			md->position.x = md->grid_cell[0] * md->position.col - 1;
			return;
		}
		md->position.col -= 1;
	}
	md->position.x = dx;
}

void	right_collision(t_main_data *md, float dx)
{
	char	temp;

	if (dx > md->grid_cell[0] * md->position.col)
	{
		temp = md->position.row->cols[md->position.col + 1];
		if (temp == '1')
		{
			md->position.x = (md->grid_cell[0] * md->position.col + 1) -5;
			return;
		}
		md->position.col += 1;
	}
	md->position.x = dx;
}
