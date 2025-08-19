/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/19 22:53:25 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	d_move(t_main_data *md)
{
	float	p_x;
	float	p_y;

	p_x = md->position.x + cos(md->position.pa + M_PI /2) * SPEED;
	p_y = md->position.y + sin(md->position.pa + M_PI / 2) * SPEED;
	if (!collision(p_x, p_y, md))
	{
		md->position.x = p_x;
		md->position.y = p_y;
	}
}

static void	a_move(t_main_data *md)
{
	float	p_x;
	float	p_y;

	p_x = md->position.x + cos(md->position.pa - M_PI /2) * SPEED;
	p_y = md->position.y + sin(md->position.pa - M_PI / 2) * SPEED;
	if (!collision(p_x, p_y, md))
	{
		md->position.x = p_x;
		md->position.y = p_y;
	}
}

static void	s_move(t_main_data *md)
{
	float	p_x;
	float	p_y;

	p_x = md->position.x;
	p_y = md->position.y;
	p_x -= cos(md->position.pa) * SPEED;
	p_y -= sin(md->position.pa) * SPEED;
	if (!collision(p_x, p_y, md))
	{
		md->position.x = p_x;
		md->position.y = p_y;
	}
}

static void	w_move(t_main_data *md)
{
	float	p_x;
	float	p_y;

	p_x = md->position.x;
	p_y = md->position.y;
	p_x += cos(md->position.pa) * SPEED;
	p_y += sin(md->position.pa) * SPEED;
	if (!collision(p_x, p_y, md))
	{
		md->position.x = p_x;
		md->position.y = p_y;
	}
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
