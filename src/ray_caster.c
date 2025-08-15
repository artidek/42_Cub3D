/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:22:37 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/15 20:43:19 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_main_data *md)
{
	float ray_angle;
	float ray_dx;
	float ray_dy;
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = md->position.pa - (FOV / 2) + (i * FOV / NUM_RAYS);
		ray_dx = cos(ray_angle);
		ray_dy = sin(ray_angle);
		if (ft_round(md->position.pa) == ft_round(NA))
			ray_forward(md, ray_dy, (md->grid_cell[0] / 2) + md->position.x,
				md->position.y);
		else if (ft_round(md->position.pa) == ft_round(SA))
			ray_back(md, ray_dy, (md->grid_cell[0] / 2) + md->position.x,
				md->position.y + md->grid_cell[1]);
		else if (ft_round(md->position.pa) == ft_round(EAN))
			ray_left(md, ray_dx, md->position.x, md->position.y + (md->grid_cell[1] / 2));
		else if (ft_round(md->position.pa) == ft_round(WA))
			ray_right(md, ray_dx, md->position.x + md->grid_cell[0], md->position.y + (md->grid_cell[1] / 2));
		// else
		// 	angle_cast(md, ray_dx, ray_dy);
		i++;
	}
}