/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:12:38 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/15 20:44:50 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static char	*extract_directory(char **env)
{
	int	i;
	char **splited;
	char	*res;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
		{
			splited = ft_split(env[i], '=');
			res = ft_strdup(splited[1]);
			free_arr(splited);
			return (res);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_main_data md;

	if (argc < 2 || argc > 2)
	{
		ft_printf("wrong number of arguments\n");
		return (1);
	}
	if (!check_ext(argv[1], "cub"))
		return (1);
	md.pwd = extract_directory(env);
	if (!init_configs(&md, argv[1]))
	{
		destroy_main_data(&md);
		return(1);
	}
	if (!start_window(&md))
	{
		ft_printf("failed to start window\n");
		destroy_main_data(&md);
		return (1);
	}
	destroy_main_data(&md);
	return (0);
}