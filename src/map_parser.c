#include "../includes/cub3d.h"

static int	check_walls(t_map *map)
{
	int	i;
	t_map *temp;

	temp = map;
	while (temp)
	{
		i = 0;
		while (temp->cols[i])
		{
			if (!valid_border(temp, i))
				return (0);
			i++;
		}
		temp = temp->down;
	}
	return (1);
}

int	check_map(t_main_data *md)
{
	if (!check_walls(md->map))
	{
		printf("cub3d map parser: unclosed walls\n");
		return (0);
	}
	return (1);
}