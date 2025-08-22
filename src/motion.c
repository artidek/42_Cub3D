/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/22 12:01:50 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	d_move(t_main_data *md)
{
	float	dir_x;
	float	dir_y;

	dir_x = md->dir_y;
	dir_y = -md->dir_x;
	if (md->grid[(int)(md->pos_y)][(int)(md->pos_x - dir_x * SPEED)] != 1)
		md->pos_x -= dir_x * SPEED;
	if (md->grid[(int)(md->pos_y - dir_y * SPEED)][(int)(md->pos_x)] != 1)
		md->pos_y -= dir_y * SPEED;
}

static void	a_move(t_main_data *md)
{
	float	dir_x;
	float	dir_y;

	dir_x = md->dir_y;
	dir_y = -md->dir_x;
	if (md->grid[(int)(md->pos_y)][(int)(md->pos_x + dir_x * SPEED)] != 1)
		md->pos_x += dir_x * SPEED;
	if (md->grid[(int)(md->pos_y + dir_y * SPEED)][(int)(md->pos_x)] != 1)
		md->pos_y += dir_y * SPEED;
}

static void	s_move(t_main_data *md)
{
	if (md->grid[(int)(md->pos_y)][(int)(md->pos_x - md->dir_x * SPEED)] != 1)
		md->pos_x -= md->dir_x * SPEED;
	if (md->grid[(int)(md->pos_y - md->dir_y * SPEED)][(int)(md->pos_x)] != 1)
		md->pos_y -= md->dir_y * SPEED;
}

static void	w_move(t_main_data *md)
{
	if (md->grid[(int)(md->pos_y)][(int)(md->pos_x + md->dir_x * SPEED)] != 1)
		md->pos_x += md->dir_x * SPEED;
	if (md->grid[(int)(md->pos_y + md->dir_y * SPEED)][(int)(md->pos_x)] != 1)
		md->pos_y += md->dir_y * SPEED;
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
