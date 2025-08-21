/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:59 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/21 16:20:57 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_object(t_main_data *md, float y_start, float y_end)
{
    int *color;

    // Choose color based on wall type
    if (md->hor)
        color = md->conf.floor_color; // horizontal wall color
    else
        color = md->conf.ceiling_color;   // vertical wall color

    // Clip y_start and y_end to screen
    if (y_start < 0)
        y_start = 0;
    if (y_end > HEIGHT)
        y_end = HEIGHT;

    // Draw vertical stripe
    for (int y = (int)y_start; y < (int)y_end; y++)
    {
        render(md->position.wall_x, y, md, color);
    }

    // Move to next vertical stripe
    md->position.wall_x += 1;
}
