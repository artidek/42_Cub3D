/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/22 01:10:02 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_object(t_main_data *md)
{
    int *color;

	if (md->side == 1)
		color = md->conf.floor_color;
	else
		color = md->conf.ceiling_color;
	//printf("start %d end %d\n", md->draw_start, md->draw_end);
	while (md->draw_start < md->draw_end)
	{
		render(md->position.wall_x, md->draw_start, md, color);
		md->draw_start += 1;
	}
	md->position.wall_x += 1;
}
