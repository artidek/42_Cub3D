#include "../includes/cub3d.h"

static int	valid_border(t_map *map)
{
	int	i;
	t_map *temp;

	temp = map;
	while(temp)
	{
		i = 0;
		while(temp->cols[i])
		{
			if (temp->cols[i] == 'a')
				return (0);
			i++;
		}
		temp = temp->down;
	}
	return (1);
}

int valid_walls(t_map *map)
{
	check_walls(map, 0);
	if (!valid_border(map))
		return (0);
	return (1);
}

static int	path(t_main_data *md)
{
	t_map *y;
	int	x;
	char player;

	if (!locate_player(md->map, &y, &x, &player))
	{
		ft_printf("Unable locate player\n");
		return (0);
	}
	parse_path(y, x);
	y->cols[x] = player;
	md->position.orientation = player;
	md->position.row = y;
	md->position.col = x;
	while(y->up)
		y = y->up;
	if (no_path(y))
	{
		ft_printf("No valid path, or one of the path invalid\n");
		return (0);
	}
	return (1);
}

int	check_map(t_main_data *md)
{
	t_map *temp;

	if (!valid_walls(md->map))
	{
		ft_printf("cub3d map parser: unclosed walls\n");
		return (0);
	}
	if (!path(md))
	{
		ft_printf("cub3d map parser: path validation failed\n");
		return (0);
	}
	md->grid_cell[0] = WIDTH / md->map->num_cols;
	temp = md->map;
	while(temp->down)
		temp = temp->down;
	md->grid_cell[1] = HEIGHT / (temp->row_index);
	return (1);
}