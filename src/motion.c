/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/12 18:22:43 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	w_move(t_main_data *md)
{
	if (md->position.row->up
		&& md->position.row->up->cols[md->position.col] != '1'
		&& md->position.y <= md->grid_cell[1] * md->position.row->row_index)
	{
		md->position.y -= 5;
		md->position.row = md->position.row->up;
		redisplay(md);
		return ;
	}
	if (md->position.row->up
		&& md->position.row->up->cols[md->position.col] == '1')
		return ;
	md->position.y -= 5;
	redisplay(md);
}

static void	s_move(t_main_data *md)
{
	if (md->position.row->down
		&& md->position.row->down->cols[md->position.col] != '1'
		&& md->position.y >= md->grid_cell[1] * md->position.row->row_index)
	{
		md->position.y += 5;
		md->position.row = md->position.row->down;
		redisplay(md);
		return ;
	}
	if (md->position.row->down
		&& md->position.row->down->cols[md->position.col] == '1')
		return ;
	md->position.y += 5;
	redisplay(md);
}

static void	a_move(t_main_data *md)
{
	if (md->position.col - 1 > 0 && md->position.x <= md->grid_cell[0]
		* md->position.col && md->position.row->cols[md->position.col
		- 1] != '1')
	{
		md->position.x -= 5;
		md->position.col -= 1;
		redisplay(md);
		return ;
	}
	if (md->position.col - 1 > 0 && md->position.row->cols[md->position.col
		- 1] == '1')
		return ;
	md->position.x -= 5;
	redisplay(md);
}

static void	d_move(t_main_data *md)
{
	if (md->position.row->cols[md->position.col + 1] && md->position.x >= md->grid_cell[0]
		* md->position.col && md->position.row->cols[md->position.col
		+ 1] != '1')
	{
		md->position.x += 5;
		md->position.col += 1;
		redisplay(md);
		return ;
	}
	if (md->position.row->cols[md->position.col + 1] > 0 && md->position.row->cols[md->position.col
		+ 1] == '1')
		return ;
	md->position.x += 5;
	redisplay(md);
}

void	move(int key_code, t_main_data *md)
{
	if (key_code == W)
		w_move(md);
	if (key_code == S)
		s_move(md);
	if (key_code == A)
		a_move(md);
	if (key_code == D)
		d_move(md);
}