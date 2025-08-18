/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:22:46 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/18 14:13:03 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	down_left(t_main_data *md, float cx, float cy)
{
	float	l_cx;
	float	l_cy;

	l_cx = cx;
	l_cy = cy;
	if (l_cx < 0)
		l_cx *= -1;
	if (l_cy < 0)
		l_cy *= -1;
	left_collision(md, md->position.x - l_cx);
	backward_collision(md, md->position.y + l_cy);
}

void	up_left(t_main_data *md, float cx, float cy)
{
	float	l_cx;
	float	l_cy;

	l_cx = cx;
	l_cy = cy;
	if (l_cx < 0)
		l_cx *= -1;
	if (l_cy < 0)
		l_cy *= -1;
	left_collision(md, md->position.x - l_cx);
	forward_collision(md, md->position.y - l_cy);
}

void	up_right(t_main_data *md, float cx, float cy)
{
	float	l_cx;
	float	l_cy;

	l_cx = cx;
	l_cy = cy;
	if (l_cx < 0)
		l_cx *= -1;
	if (l_cy < 0)
		l_cy *= -1;
	right_collision(md, md->position.x + l_cx);
	forward_collision(md, md->position.y - l_cy);
}

void	down_right(t_main_data *md, float cx, float cy)
{
	float	l_cx;
	float	l_cy;

	l_cx = cx;
	l_cy = cy;
	if (l_cx < 0)
		l_cx *= -1;
	if (l_cy < 0)
		l_cy *= -1;
	right_collision(md, md->position.x + l_cx);
	backward_collision(md, md->position.y + l_cy);
}
