/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:12:38 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/29 21:35:25 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_main_data md;

	if (argc < 2 || argc > 2)
	{
		ft_printf("wrong number of arguments\n");
		return (1);
	}
	if (!check_ext(argv[2], "cub"))
		return (1);
	if (!init_configs(&md, argv[1]))
	{
		free_data(md);
		return(1);
	}
	if (!start_window(&md))
	{
		free_data(md);
		return (1);
	}
	start_maze(md);
	free_data(md);
	return (0);
}