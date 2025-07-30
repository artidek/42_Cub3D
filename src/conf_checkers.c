/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:59:02 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/30 21:22:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_f_c(char *str, char *line)
{
	int	fd;
	char **splited;
	char **colors;

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
	return (1);
}

static int	is_conf(char *str, char *line)
{
	int len;

	len = ft_strlen(str);
	if (len == 1 && is_f_c(str, line))
		return (1);
	if (len == 2 && is_text(str, line))
		return (1);
	if (len > 2 && is_map(str, line))
		return (1);
	return (0);
}

int	check_line(char *line)
{
	int	i;
	char	*check;

	i = 0;
	check = NULL;
	if (line[0] == ' ')
		skip_char(line, &i, ' ');
	if (!line[i])
		return (0);
	while (line[i] && line[i] != ' ' && line[i] != '\n')
	{
		add_to_str(&check, 1, &line[i]);
		i++;
	}
	if (!is_conf(check, line))
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}