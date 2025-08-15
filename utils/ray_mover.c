/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:54:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/15 20:43:28 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_forward(t_main_data *md, float ray_dy, float mid, float pos_y)
{
	t_map	*row;

	row = md->position.row;
	if (ft_round(md->position.pa) == ft_round(NA))
	{
		while (row)
		{
			if (row->cols[md->position.col] == '1')
				break ;
			render(mid, pos_y, md, RAY_COLOR);
			pos_y -= ray_dy;
			if (pos_y < md->grid_cell[1] * row->row_index)
				row = row->up;
		}
	}
}

void	ray_back(t_main_data *md, float ray_dy, float mid_x, float pos_y)
{
	t_map *row;

	row = md->position.row;
	while (row)
	{
		if (row->cols[md->position.col] == '1')
			break ;
		pos_y -= ray_dy;
		render(mid_x, pos_y, md, RAY_COLOR);
		if (pos_y > md->grid_cell[1] * row->row_index)
		{
			render(mid_x, pos_y, md, RAY_COLOR);
			row = row->down;
		}
	}
}

void	ray_left(t_main_data *md, float dx, float pos_x, float pos_y)
{
	int	col;

	col = md->position.col;
	while (col > 0)
	{
		if (md->position.row->cols[col] == '1')
			break;
		pos_x += dx;
		render(pos_x, pos_y, md, RAY_COLOR);
		if (pos_x < md->grid_cell[0] * col)
		{
			render(pos_x, pos_y, md, RAY_COLOR);
			col--;
		}
	}
}

void	ray_right(t_main_data *md, float dx, float pos_x, float pos_y)
{
	int	col;

	col = md->position.col;
	while (md->position.row->cols[col])
	{
		if (md->position.row->cols[col] == '1')
			break;
		pos_x += dx;
		render(pos_x, pos_y, md, RAY_COLOR);
		if (pos_x > md->grid_cell[0] * col)
		{
			render(pos_x, pos_y, md, RAY_COLOR);
			col++;
		}
	}
}