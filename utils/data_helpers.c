/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:24:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/09 21:00:04 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("file doesn't exist or invalid permission\n");
		return (fd);
	}
	return (fd);
}

void	skip_line(int fd, int num_lines)
{
	int	i;
	char	*line;

	line = get_next_line(fd);
	while (line && i < num_lines)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	get_size(int fd, int *width, int *height)
{
	char	*line;
	char	**splited;

	line = get_next_line(fd);
	if (line)
	{
		splited = ft_split(line, ' ');
		*width = ft_atoi(splited[0]);
		*height = ft_atoi(splited[1]);
	}
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
			ret[i][j] = ft_atoi(line);
			j++;
			free(line);
		}
		i++;
	}
	return (ret);
}

int	valid_texture(int fd)
{
	int	width;
	int	height;
	int count;
	char	*line;

	width = 0;
	height = 0;
	count = 0;
	skip_line(fd, 3);
	get_size(fd, &width, &height);
	line = get_next_line(fd);
	while(line && line[0] != '\n')
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	if (count != height * width * 3)
	{
		printf("invalid or corrupted texture\n");
		close(fd);
		return (0);
	}
	return (1);
}