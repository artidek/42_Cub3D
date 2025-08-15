/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/15 17:02:15 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	w_move(t_main_data *md, float c_x, float c_y)
{
	if (ft_round(md->position.pa) == ft_round(NA))
		forward_collision(md,md->position.y - 5);
	if(ft_round(md->position.pa) == ft_round(SA))
		backward_collision(md,md->position.y + 5);
	if (ft_round(md->position.pa) == ft_round(EAN))
		left_collision(md, md->position.x - 5);
	if (ft_round(md->position.pa) == ft_round(WA))
		right_collision(md, md->position.x + 5);
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
		up_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
		down_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(SA))
		down_right(md, c_x, c_y);
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
		up_right(md, c_x, c_y);
	redisplay(md);
}

static void	s_move(t_main_data *md, float c_x, float c_y)
{
	if (ft_round(md->position.pa) == ft_round(NA))
		backward_collision(md,md->position.y + 5);
	if (ft_round(md->position.pa) == ft_round(SA))
		forward_collision(md,md->position.y - 5);
	if (ft_round(md->position.pa) == ft_round(EAN))
		left_collision(md, md->position.x - 5);
	if (ft_round(md->position.pa) == ft_round(WA))
		right_collision(md, md->position.x + 5);
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
		down_right(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
		up_right(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(SA))
		up_left(md, c_x, c_y);
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
		down_left(md, c_x, c_y);
	redisplay(md);
}

static void	a_move(t_main_data *md, float c_x, float c_y)
{
	if (ft_round(md->position.pa) == ft_round(NA))
	{
		left_collision(md, md->position.x - 5);
		redisplay(md);
		return ;
	}
	if (ft_round(md->position.pa) == ft_round(SA))
	{
		right_collision(md, md->position.x + 5);
		redisplay(md);
		return ;
	}
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
		up_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
		down_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(SA))
		down_right(md, c_x, c_y);
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
		up_right(md, c_x, c_y);
	redisplay(md);
}

static void	d_move(t_main_data *md, float c_x, float c_y)
{
	printf("cx %f\n", c_x);
	if (ft_round(md->position.pa) == ft_round(NA))
	{
		right_collision(md, md->position.x + 5);
		redisplay(md);
		return ;
	}
	if (ft_round(md->position.pa) == ft_round(SA))
	{
		left_collision(md, md->position.x - 5);
		redisplay(md);
		return ;
	}
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
		up_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
		down_left(md, c_x, c_y);
	if (ft_round(md->position.pa) > ft_round(SA))
		down_right(md, c_x, c_y);
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
		up_right(md, c_x, c_y);
	redisplay(md);
}

void	move(int key_code, t_main_data *md)
{
	float c_x;
	float c_y;

	c_x = cos(md->position.pa) * 5;
	c_y = sin(md->position.pa) * 5;
	if (key_code == W)
		w_move(md, c_x, c_y);
	if (key_code == S)
		s_move(md, c_x, c_y);
	if (key_code == A)
		a_move(md, c_x, c_y);
	if (key_code == D)
		d_move(md, c_x, c_y);
}