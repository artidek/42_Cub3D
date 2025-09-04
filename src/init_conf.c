/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:31:05 by aobshatk          #+#    #+#             */
/*   Updated: 2025/09/04 15:15:23 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	invalid_config(t_main_data *md)
{
	if (!md->conf.textures[0].text_arr)
		return (1);
	if (!md->conf.textures[1].text_arr)
		return (1);
	if (!md->conf.textures[2].text_arr)
		return (1);
	if (!md->conf.textures[3].text_arr)
		return (1);
	if (md->conf.floor_color == -1)
		return (1);
	if (md->conf.ceiling_color == -1)
		return (1);
	if (!md->map)
		return (1);
	return (0);
}

static void	init_data(t_main_data *md)
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
	md->conf.floor_color = -1;
	md->conf.ceiling_color = -1;
	md->map = NULL;
	md->position.x = 0;
	md->position.y = 0;
	md->turn_key = 0;
	md->grid = NULL;
	md->pwd = ft_strdup(WIAM);
}

static int	read_file(t_main_data *md, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!check_line(line, md, fd))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	init_configs(t_main_data *md, char *conf_path)
{
	int	fd;

	init_data(md);
	fd = open(conf_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: invalid path or file doesn't exist\n");
		return (0);
	}
	if (!read_file(md, fd) || invalid_config(md))
	{
		ft_printf("Error: invalid config\n");
		return (0);
	}
	if (!check_map(md))
	{
		ft_printf("Error: invalid map\n");
		return (0);
	}
	close(fd);
	return (1);
}
