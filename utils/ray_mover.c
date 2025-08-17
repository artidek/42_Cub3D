/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:54:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/17 22:12:58 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ray_forward(t_main_data *md, t_map **row, float pos_y, float ray_dy)
{
	if (ft_round(ray_dy) < 0)
		ray_dy *= -1;
	pos_y -= ray_dy;
	if (pos_y < md->grid_cell[1] * (*row)->row_index)
		(*row) = (*row)->up;
	return (pos_y);
}

float	ray_back(t_main_data *md, t_map **row, float pos_y, float ray_dy)
{
	if (ft_round(ray_dy) < 0)
		ray_dy *= -1;
	pos_y += ray_dy;
	if (pos_y > md->grid_cell[1] * (*row)->row_index)
		(*row) = (*row)->down;
	return (pos_y);
}

float	ray_left(t_main_data *md, int *col_index, float pos_x, float dx)
{
	int	x_size;

	x_size = md->grid_cell[0];
	if (ft_round(dx) < 0)
		dx *= -1;
	pos_x -= dx;
	if (pos_x < x_size * (*col_index))
		*col_index -= 1;
	return (pos_x);
}

float	ray_right(t_main_data *md, int *col_index, float pos_x, float dx)
{
	int	x_size;

	x_size = md->grid_cell[0];
	if (ft_round(dx) < 0)
		dx *= -1;
	pos_x += dx;
	if (pos_x > x_size * (*col_index))
		*col_index += 1;
	return (pos_x);
}