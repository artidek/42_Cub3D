/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:01:40 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/10 19:23:45 by aobshatk         ###   ########.fr       */
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
	temp = *map;
	while (temp->down)
		temp = temp->down;
	node->up = temp;
	temp->down = node;
}

void	add_texture(t_main_data *md, char *path, int texture)
{
	int	fd;
	int	width;
	int	height;

	fd = valid_path(path, md->pwd);
	if (fd < 0)
		return ;
	skip_line(fd, 2);
	get_size(fd, &width, &height);
	if (!valid_texture(fd, width, height))
		return ;
	md->conf.textures[texture].text_arr = init_text_arr(fd, width, height);
	md->conf.textures[texture].type = texture;
	md->conf.textures[texture].width = width;
	md->conf.textures[texture].height = height;
	close(fd);
}

void	add_color(char *type, char *color, t_main_data *md)
{
	int i;
	int j;
	char *color_val;

	i = 0;
	j = 0;
	color_val = NULL;
	while (color[i])
	{
		if (ft_isdigit(color[i]))
		{
			add_to_str(&color_val, 3, &color[i]);
			if (type[0] == 'F')
				md->conf.floor_color[j] = ft_atoi(color_val);
			if (type[0] == 'C')
				md->conf.ceiling_color[j] = ft_atoi(color_val);
			j++;
			free(color_val);
			color_val = NULL;
			i += 2;
		}
		if (color[i])
			i++;
	}
}