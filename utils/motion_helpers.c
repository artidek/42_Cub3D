/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:44:21 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/13 19:46:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_main_data *md)
{
	if (front_collision(md, md->position.y))
		return;
	if(md->position.y < md->grid_cell[1] * md->position.row->row_index)
		md->position.row = md->position.row->up;
}

void	move_down(t_main_data *md)
{
	if (back_collision(md, md->position.y))
		return;
	if(md->position.y > md->grid_cell[1] * md->position.row->row_index)
		md->position.row = md->position.row->down;
}

void	move_left(t_main_data *md)
{
	if (left_collision(md, md->position.x))
		return;
	if (md->position.x < md->grid_cell[0] * md->position.col)
		md->position.col -= 1;
}

void	move_right(t_main_data *md)
{
	if (right_collision(md, md->position.x))
		return;
	if (md->position.x > md->grid_cell[0] * md->position.col)
		md->position.col += 1;
}

float	get_x(t_main_data *md, int key)
{
	if (key == S)
		return (md->position.x + cos(md->position.pa) * 5);
	if (key == W)
		return (md->position.x - cos(md->position.pa) * 5);
	return (md->position.x);
}