/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/19 23:35:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_object(t_main_data *md, float y_start, float y_end)
{
	if (y_start < 0)
	{
		y_end += y_start;
		y_start = 0;
	}
	while (y_start < y_end)
	{
		render(md->position.wall_x, y_start, md, md->conf.floor_color);
		y_start++;
	}
	md->position.wall_x += 1;
}
