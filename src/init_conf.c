/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:31:05 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/09 21:29:11 by aobshatk         ###   ########.fr       */
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
	md->conf.textures[NO].text_arr = NULL;
	md->conf.textures[SO].text_arr = NULL;
	md->conf.textures[EA].text_arr = NULL;
	md->conf.textures[WE].text_arr = NULL;
	md->conf.floor_color[0] = -1;
	md->conf.ceiling_color[0] = -1;
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
			if (!check_line(line, md))
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
	// if (!check_data(md))
	// {
	// 	ft_printf("invalid configuration\n");
	// 	return (0);
	// }
	// if (!check_map(md))
	// {
	// 	ft_printf("invalid map\n");
	// 	return (0);
	// }
	close(fd);
	return (1);
}