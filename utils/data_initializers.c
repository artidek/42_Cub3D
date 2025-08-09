/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:01:40 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/09 21:00:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*new_node(char *cols)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->up = NULL;
	node->down = NULL;
	node->cols = ft_strdup(cols);
	return (node);
}

void	add_node(t_map **map, t_map *node)
{
	t_map	*temp;

	if (!*map)
	{
		*map = node;
		return ;
	}
	while (temp->down)
		temp = temp->down;
	node->up = temp;
	temp->down = node;
}

void	add_texture(t_main_data *md, char *path, int texture)
{
	int fd;
	int width;
	int height;

	fd = valid_path(path);
	if (fd < 0)
		return;
	if (!valid_texture(fd))
		return;
	skip_line(fd, 3);
	get_size(fd, &width, &height);
	md->conf.textures[texture].text_arr = init_text_arr(fd, width, height);
	md->conf.textures[texture].type = texture;
	md->conf.textures[texture].width = width;
	md->conf.textures[texture].height = height;
	close(fd);
}

void	add_color(char *type, char *color, t_main_data *md)
{
	char	**splited;

	splited = ft_split(color, ',');
	if (ft_strncmp(type, "F", 1))
	{
		md->conf.floor_color[0] = ft_atoi(splited[0]);
		md->conf.floor_color[1] = ft_atoi(splited[1]);
		md->conf.floor_color[2] = ft_atoi(splited[2]);
	}
	if (ft_strncmp(type, "C", 1))
	{
		md->conf.ceiling_color[0] = ft_atoi(splited[0]);
		md->conf.ceiling_color[1] = ft_atoi(splited[1]);
		md->conf.ceiling_color[2] = ft_atoi(splited[2]);
	}
	free_arr(splited);
}