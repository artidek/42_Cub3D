/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:24:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/10 19:39:25 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int valid_path(char *path, char *dir)
{
	int	fd;
	char	**splited;
	char	*full_path;

	splited = ft_split(path, ' ');
	splited[1][ft_strlen(splited[1]) - 1] = 0;
	full_path = ft_strjoin(dir, &splited[1][1]);
	fd = open(full_path, O_RDWR);
	free(full_path);
	if (fd < 0)
	{
		printf("file doesn't exist or invalid permission\n");
		free_arr(splited);
		return (fd);
	}
	free_arr(splited);
	return (fd);
}

void	skip_line(int fd, int num_lines)
{
	int	i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	i++;
	while (line && i < num_lines)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
}

void	get_size(int fd, int *width, int *height)
{
	char	*line;
	char	**splited;

	line = get_next_line(fd);
	line[ft_strlen(line) - 1] = 0;
	if (line)
	{
		splited = ft_split(line, ' ');
		*width = ft_atoi(splited[0]);
		*height = ft_atoi(splited[1]);
	}
	free_arr(splited);
	free(line);
}

int	**init_text_arr(int fd, int width, int height)
{
	int	**ret;
	int i;
	int	j;
	char	*line;

	ret = malloc(sizeof(int *) * height);
	i = 0;
	j = 0;
	while (i < height)
	{
		ret[i] = malloc(sizeof(int) * width * 3);
		while (j < width * 3)
		{
			line = get_next_line(fd);
			if (line && line[0] != '\n')
				ret[i][j] = ft_atoi(line);
			j++;
			free(line);
		}
		i++;
	}
	return (ret);
}

int	valid_texture(int fd, int width, int height)
{
	int count;
	char	*line;

	skip_line(fd, 1);
	count = 0;
	line = get_next_line(fd);
	while(line && line[0] != '\n')
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count != height * width * 3)
	{
		printf("invalid or corrupted texture\n");
		close(fd);
		return (0);
	}
	return (1);
}