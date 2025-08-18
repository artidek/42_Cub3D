/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:22:37 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/18 14:32:00 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_dir(float ra, float dir)
{
	if (dir == ft_round(NA))
	{
		if (ra > dir && ra < ft_round(EAN))
			return (1);
	}
	if (dir == ft_round(EAN))
	{
		if (ra > dir && ra < ft_round(SA))
			return (1);
	}
	if (dir == ft_round(SA))
	{
		if (ra > dir)
			return (1);
	}
	return (0);
}

static void	draw_wall(t_main_data *md, float pos_x, float pos_y)
{
	float	distance;
	float	dx;
	float	dy;
	float	p_distance;

	dx = pos_x - md->position.x;
	dy = pos_y - md->position.y;
	distance = sqrt((dx * dx) + (dy * dy));
	p_distance = distance * cos(md->position.ra - md->position.pa);
	md->position.wall_x = 0;
	draw_object(md, HEIGHT/2 - (HEIGHT/p_distance)/2, HEIGHT/2 + (HEIGHT/p_distance)/2);
}

static void	diagonal_move(t_main_data *md, int *col_index, float *pos_x,
		float *pos_y)
{
	t_map	*row;

	row = md->position.row;
	while (row->cols[*col_index] != '1' && check_dir(ft_round(md->position.ra),
			ft_round(NA)))
	{
		*pos_x = ray_left(md, col_index, *pos_x, md->position.step_x);
		*pos_y = ray_forward(md, &row, *pos_y, md->position.step_y);
	}
	while (row->cols[*col_index] != '1' && check_dir(ft_round(md->position.ra),
			ft_round(EAN)))
	{
		*pos_x = ray_left(md, col_index, *pos_x, md->position.step_x);
		*pos_y = ray_back(md, &row, *pos_y, md->position.step_y);
	}
	while (row->cols[*col_index] != '1' && check_dir(ft_round(md->position.ra),
			ft_round(SA)))
	{
		*pos_x = ray_right(md, col_index, *pos_x, md->position.step_x);
		*pos_y = ray_back(md, &row, *pos_y, md->position.step_y);
	}
	while (row->cols[*col_index] != '1'
		&& ft_round(md->position.ra) < ft_round(NA))
	{
		*pos_x = ray_left(md, col_index, *pos_x, md->position.step_x);
		*pos_y = ray_forward(md, &row, *pos_y, md->position.step_y);
	}
}

static void	start_moving(t_main_data *md, int *col_index, float *pos_x,
		float *pos_y)
{
	t_map	*row;

	row = md->position.row;
	while (row->cols[*col_index] != '1'
		&& ft_round(md->position.ra) == ft_round(NA))
		*pos_y = ray_forward(md, &row, *pos_y, md->position.step_y);
	while (row->cols[*col_index] != '1'
		&& ft_round(md->position.ra) == ft_round(SA))
		*pos_y = ray_back(md, &row, *pos_y, md->position.step_y);
	while (row->cols[*col_index] != '1'
		&& ft_round(md->position.ra) == ft_round(EAN))
		*pos_x = ray_left(md, col_index, *pos_x, md->position.step_x);
	while (row->cols[*col_index] != '1'
		&& ft_round(md->position.ra) == ft_round(WA))
		*pos_x = ray_left(md, col_index, *pos_x, md->position.step_x);
	if (ft_round(md->position.ra) != ft_round(NA)
		&& ft_round(md->position.ra) != ft_round(SA)
		&& ft_round(md->position.ra) != ft_round(EAN)
		&& ft_round(md->position.ra) != ft_round(WA))
		diagonal_move(md, col_index, pos_x, pos_y);
	draw_wall(md, *pos_x, *pos_y);
}

static void	move_rays(t_main_data *md)
{
	int		col_index;
	float	pos_x;
	float	pos_y;

	col_index = md->position.col;
	pos_x = md->position.x;
	pos_y = md->position.y;
	start_moving(md, &col_index, &pos_x, &pos_y);
}

void	cast_rays(t_main_data *md)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		md->position.ra = md->position.pa - (FOV / 2) + (i * FOV / NUM_RAYS);
		md->position.step_x = cos(md->position.ra);
		md->position.step_y = sin(md->position.ra);
		move_rays(md);
		i++;
	}
}
