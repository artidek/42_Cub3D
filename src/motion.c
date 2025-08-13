/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/13 20:05:13 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	w_move(t_main_data *md)
{
	if (!front_collision(md, md->position.y - sin(md->position.pa) * 5))
	{
		if (md->turn_key == LEFT)
		{
			if (!left_collision(md, get_x(md, W)))
			{
				move_up(md);
				move_left(md);
				redisplay(md);
				return;
			}
		}
		if(md->turn_key == RIGHT)
		{
			if (!right_collision(md, get_x(md, W)))
			{
				move_up(md);
				move_right(md);
				redisplay(md);
				return;
			}
		}
		move_up(md);
	}
	redisplay(md);
}

static void	s_move(t_main_data *md)
{
	if (!back_collision(md, md->position.y + sin(md->position.pa) * 5))
	{
		if (md->turn_key == LEFT)
		{
			if (!right_collision(md, get_x(md, S)))
			{
				move_down(md);
				move_right(md);
				redisplay(md);
				return;
			}
		}
		if(md->turn_key == RIGHT)
		{
			if (!left_collision(md, get_x(md, S)))
			{
				move_down(md);
				move_left(md);
				redisplay(md);
				return;
			}
		}
		move_down(md);
	}
	redisplay(md);
}

static void	a_move(t_main_data *md)
{
	if (md->position.col - 1 > 0 && md->position.row->cols[md->position.col
		- 1] == '1')
		return ;
	if (md->position.col - 1 > 0 && md->position.x <= md->grid_cell[0]
		* md->position.col && md->position.row->cols[md->position.col
		- 1] != '1')
	{
		md->position.x -= 5;
		md->position.col -= 1;
		redisplay(md);
		return ;
	}
	md->position.x -= 5;
	redisplay(md);
}

static void	d_move(t_main_data *md)
{
	if (md->position.row->cols[md->position.col + 1] > 0 && md->position.row->cols[md->position.col
		+ 1] == '1')
		return ;
	if (md->position.row->cols[md->position.col + 1] && md->position.x >= md->grid_cell[0]
		* md->position.col && md->position.row->cols[md->position.col
		+ 1] != '1')
	{
		md->position.x += 5;
		md->position.col += 1;
		redisplay(md);
		return ;
	}
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