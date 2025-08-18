/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/18 17:05:31 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_object(t_main_data *md, int y_start, int y_end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (y_start < y_end)
	{
		while (j < md->grid_cell[1])
		{
			while (i < md->grid_cell[0])
			{
				render(md->position.wall_x + i, HEIGHT - y_start, md, md->conf.floor_color);
				i++;
			}
			j++;
		}
		i = 0;
		j = 0;
		y_start++;
	}
}
