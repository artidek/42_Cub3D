/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:51:53 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 16:36:13 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_coords(t_main_data *md)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < md->grid_size[0])
	{
		while (j < md->grid_size[1])
		{
			if (md->grid[i][j] == 'N' || md->grid[i][j] == 'S'
				|| md->grid[i][j] == 'E' || md->grid[i][j] == 'W')
			{
				md->position.x = j * md->cell_size[1];
				md->position.y = i * md->cell_size[0];
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	num_rows(t_main_data *md)
{
	t_map	*temp;

	temp = md->map;
	while (temp->down)
		temp = temp->down;
	return (temp->row_index);
}

static void	fill_cols(t_map *row, int *cells)
{
	int	i;

	i = 0;
	while (row->cols[i])
	{
		if (row->cols[i] == ' ')
			cells[i] = -1;
		else if (row->cols[i] == 'x')
			cells[i] = 0;
		else if (row->cols[i] == '1')
			cells[i] = 1;
		else
			cells[i] = row->cols[i];
		i++;
	}
}

int	build_grid(t_main_data *md)
{
	t_map	*temp;
	int		y_size;
	int		x_size;

	y_size = num_rows(md);
	md->grid = malloc(sizeof(int *) * y_size);
	temp = md->map;
	x_size = temp->num_cols;
	md->grid_size[1] = x_size;
	while (temp)
	{
		md->grid_size[0] = temp->row_index;
		md->grid[temp->row_index - 1] = malloc(sizeof(int) * temp->num_cols);
		fill_cols(temp, md->grid[temp->row_index - 1]);
		temp = temp->down;
	}
	set_player_coords(md);
	return (1);
}
