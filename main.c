/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:12:38 by aobshatk          #+#    #+#             */
/*   Updated: 2025/09/02 13:49:00 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// static char	*extract_directory(char **env)
// {
// 	int		i;
// 	char	**splited;
// 	char	*res;

// 	i = 0;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], "PWD", 3) == 0)
// 		{
// 			splited = ft_split(env[i], '=');
// 			res = ft_strdup(splited[1]);
// 			free_arr(splited);
// 			return (res);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

static int	initialization(t_main_data *md, char *conf_file)
{
	char	*conf_path;

	conf_path = get_conf_path(conf_file);
	if (!init_configs(md, conf_path))
	{
		destroy_main_data(md);
		free(conf_path);
		return (0);
	}
	if (!build_grid(md))
	{
		destroy_main_data(md);
		free(conf_path);
		return (0);
	}
	free(conf_path);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main_data	md;

	if (argc < 2 || argc > 2)
	{
		ft_printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!check_ext(argv[1], "cub"))
		return (1);
	if (!initialization(&md, argv[1]))
		return (1);
	if (!start_window(&md))
	{
		ft_printf("Error: failed to start window\n");
		destroy_main_data(&md);
		return (1);
	}
	destroy_main_data(&md);
	return (0);
}
