/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:59:02 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/24 11:09:40 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_map(char *line, int fd, t_main_data *md)
{
	char *row;

	line[ft_strlen(line) - 1] = 0;
	if (!check_row(line))
		return (0);
	add_node(&(md->map), new_node(line));
	row = get_next_line(fd);
	if (!row)
		return (0);
	while(row && row[0] != '\n')
	{
		row[ft_strlen(row) - 1] = 0;
		if (check_row(row))
			add_node(&(md->map), new_node(row));
		else
		{
			free(row);
			return (0);
		}
		free(row);
		row = get_next_line(fd);	
	}
	if (row)
		free(row);
	return (1);
}

static int	is_text(char *str)
{
	int	i;
	int texture;
	int len;
	char **conf;

	i = 0;
	texture = -1;
	len = ft_strlen(str);
	conf = CONFIGS;
	while (i < 4)
	{
		if (len == 2 && ft_strncmp(str, conf[i], 2) == 0)
		{
			texture = i;
			return (texture);
		}
		i++;
	}
	return (texture);
}

static int	is_f_c(char *str, char *line, t_main_data *md)
{
	char	**splited;
	char	**colors;

	if (!is_config(str))
		return (0);
	splited = ft_split(line, ' ');
	if (arr_len(splited) < 2)
	{
		free_arr(splited);
		return (0);
	}
	colors = ft_split(splited[1], ',');
	free_arr(splited);
	if (arr_len(colors) != 3 || !is_colors(colors))
	{
		free_arr(colors);
		return (0);
	}
	free_arr(colors);
	add_color(str, line, md);
	return (1);
}

static int	is_conf(char *str, char *line, t_main_data *md, int fd)
{
	int	len;
	int texture;

	len = 0;
	if (line[0] == '\n')
		return (1);
	if (str)
		len = ft_strlen(str);
	if (len == 1 && is_f_c(str, line, md))
		return (1);
	if (len == 2)
	{
		texture = is_text(str);
		if (texture >= 0)
		{
			add_texture(md, line, texture);
			return (1);
		}
	}
	if (is_map(line, fd, md))
		return (1);
	return (0);
}

int	check_line(char *line, t_main_data *md, int fd)
{
	int i;
	char *check;

	i = 0;
	check = NULL;
	skip_char(line, &i, " 	");
	if (!line[i])
		return (0);
	while (line[i] && line[i] != ' ' && line[i] != '\n')
	{
		add_to_str(&check, 1, &line[i]);
		i++;
	}
	if (!is_conf(check, line, md, fd))
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}