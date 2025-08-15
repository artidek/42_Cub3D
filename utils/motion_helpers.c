/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:22:46 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/15 14:06:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	down_left(t_main_data *md, float cx, float cy)
{
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
	{
		left_collision(md, md->position.x - cx);
		backward_collision(md, md->position.y + cy);
	}
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
	{
		left_collision(md, md->position.x + cx);
		backward_collision(md, md->position.y - cy);
	}
}

void up_left(t_main_data *md, float cx, float cy)
{
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
	{
		left_collision(md, md->position.x + cx);
		forward_collision(md, md->position.y - cy);
	}
	if (ft_round(md->position.pa) > ft_round(SA))
	{
		left_collision(md, md->position.x - cx);
		forward_collision(md, md->position.y + cy);
	}
}

void	up_right(t_main_data *md, float cx, float cy)
{
	if (ft_round(md->position.pa) < ft_round(NA) && ft_round(md->position.pa) > 0)
	{
		right_collision(md, md->position.x + cx);
		forward_collision(md, md->position.y - cy);
	}
	if (ft_round(md->position.pa) > ft_round(EAN) && ft_round(md->position.pa) < ft_round(SA))
	{
		right_collision(md, md->position.x - cx);
		forward_collision(md, md->position.y + cy);
	}
}

void down_right(t_main_data *md, float cx, float cy)
{
	if (ft_round(md->position.pa) > ft_round(NA) && ft_round(md->position.pa) < ft_round(EAN))
	{
		right_collision(md, md->position.x - cx);
		backward_collision(md, md->position.y + cy);
	}
	if (ft_round(md->position.pa) > ft_round(SA))
	{
		right_collision(md, md->position.x + cx);
		backward_collision(md, md->position.y - cy);
	}
}