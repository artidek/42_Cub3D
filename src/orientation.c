/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:48:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/19 22:39:43 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	orientation(int key_code, t_main_data *md)
{
	if (key_code == LEFT)
	{
		if (roundf((md->position.pa - 0.17) * 100) / 100 <= 0)
			md->position.pa = 2 * M_PI;
		else 
			md->position.pa -= 0.1;
	}
	if (key_code == RIGHT)
	{
		if (roundf((md->position.pa + 0.17) * 100) / 100 >= 2 * M_PI)
			md->position.pa = 0;
		else
			md->position.pa += 0.1;
	}
}

void set_initial_orientation(t_main_data *md)
{
	if (md->position.orientation == 'N')
		md->position.pa = 3 * M_PI / 2; 
	if (md->position.orientation == 'S')
		md->position.pa = M_PI / 2; 
	if (md->position.orientation == 'E')
		md->position.pa = 0;
	if (md->position.orientation == 'W')
		md->position.pa =  M_PI;
	md->position.ia = md->position.pa;
}