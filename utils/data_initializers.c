/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:01:40 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 16:29:43 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	add_to_md(t_main_data *md, char *type, int color_int[3])
{
	if (*type == 'F')
		md->conf.floor_color = color(color_int);
	if (*type == 'C')
		md->conf.ceiling_color = color(color_int);
}

t_map	*new_node(char *cols)
{
	t_map	*node;
	int		cols_count;

	if (!cols)
		return (NULL);
	cols_count = ft_strlen(cols);
	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->row_index = 0;
	node->num_cols = cols_count;
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
		(*map)->row_index += 1;
		return ;
	}
	temp = *map;
	while (temp->down)
		temp = temp->down;
	node->row_index = temp->row_index + 1;
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
	fd = valid_path(path, md->pwd);
	skip_line(fd, 4);
	md->conf.textures[texture].text_arr = init_text_arr(fd, width, height);
	md->conf.textures[texture].type = texture;
	md->conf.textures[texture].width = width;
	md->conf.textures[texture].height = height;
	close(fd);
}

void	add_color(char *type, char *color, t_main_data *md)
{
	int		i;
	int		j;
	char	*color_val;

	i = 0;
	j = 0;
	color_val = NULL;
	while (color[i])
	{
		if (ft_isdigit(color[i]))
		{
			add_to_str(&color_val, 3, &color[i]);
			if (type[0] == 'F')
				md->color_int[j] = ft_atoi(color_val);
			if (type[0] == 'C')
				md->color_int[j] = ft_atoi(color_val);
			j++;
			free(color_val);
			color_val = NULL;
			i += 2;
		}
		if (color[i])
			i++;
	}
	add_to_md(md, type, md->color_int);
}
