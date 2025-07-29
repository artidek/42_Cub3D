/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:31:05 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/29 21:33:54 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void init_data(t_main_data *md)
{
	md->wind.bpp = -1;
	md->wind.data = NULL;
	md->wind.endian = -1;
	md->wind.img = NULL;
	md->wind.line_size = -1;
	md->wind.mlx = NULL;
	md->wind.win = NULL;
	md->conf.e_text = NULL;
	md->conf.n_text = NULL;
	md->conf.s_text = NULL;
	md->conf.w_text = NULL;
	md->map = NULL;
}

static void read_file(t_main_data *md, int fd)
{
	char *line;

	line = get_next_line(fd);
	if (!line)
		return;
	while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		{
			if (!check_line(line))
			{
				close(fd);
				return;
			}
		}
		line = get_next_line(fd);
	}
}

int init_configs(t_main_data *md, char *conf_path)
{
	int fd;

	init_data(md);
	fd = open(conf_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("invalid path or file doesn't exist\n");
		return (0);
	}
	read_file(md, fd);
	if (!check_data(md))
	{
		ft_printf("invalid configuration\n");
		return (0);
	}
	if (!check_map(md))
	{
		ft_printf("invalid map\n");
		return (0);
	}
	close(fd);
	return (1);
}