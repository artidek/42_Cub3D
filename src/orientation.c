/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:48:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/12 15:15:15 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	orientation(int key_code, t_main_data *md)
{
	if (key_code == S)
		md->position.orientation = 'S';
	if (key_code == W)
		md->position.orientation = 'N';
	if (key_code == A)
		md->position.orientation = 'E';
	if (key_code == D)
		md->position.orientation = 'W';
	if (key_code == LEFT && md->position.orientation == 'S')
		md->position.orientation = 'W';
	if(key_code == LEFT && md->position.orientation == 'N')
		md->position.orientation = 'E';
	if(key_code == LEFT && md->position.orientation == 'E')
		md->position.orientation = 'S';
	if(key_code == LEFT && md->position.orientation == 'W')
		md->position.orientation = 'N';
	if (key_code == RIGHT && md->position.orientation == 'S')
		md->position.orientation = 'E';
	if(key_code == RIGHT && md->position.orientation == 'N')
		md->position.orientation = 'W';
	if(key_code == RIGHT && md->position.orientation == 'E')
		md->position.orientation = 'N';
	if(key_code == RIGHT && md->position.orientation == 'W')
		md->position.orientation = 'S';
}