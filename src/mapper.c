/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:10:06 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/12 14:53:46 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void draw_player(t_main_data *md)
{
	int i = 0;
	int	j;
	while (i < md->grid_cell[1])
	{
		j = 0;
		while (j < md->grid_cell[1])
		{
			render(md->position.x + j, md->position.y + i, md, 'P');
			j++;
		}
		i++;
	}
}

static void	draw_wall(int x, int y, t_main_data *md)
{
	int height = md->grid_cell[1];
	int width = md->grid_cell[0];
	int i;
	while (height > 0 && y < HEIGHT)
	{
		i = 0;
		while (i < width)
		{
			render(x + i, y, md, 'W');
			i ++;
		}
		y++;
		height--;
	}
}

void	draw_map(t_main_data *md)
{
	int i;
	t_map *temp = md->map;

	while(temp)
	{
		i = 0;
		while(temp->cols[i])
		{
			if(temp->cols[i] == '1')
			{
				draw_wall(md->grid_cell[0] * i, md->grid_cell[1] * temp->row_index, md);
			}
			i++;
		}
		temp = temp->down;
	}
	draw_player(md);
}