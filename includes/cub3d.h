/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:13 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/11 10:11:09 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/ft_printf/libftprintf.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <linux/input-event-codes.h>
# include <linux/input.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define MAP_SYMB "NWSE01 "
# define CONFIGS                                \
	(char *[])                                 \
	{                                          \
		"NO", "SO", "EA", "WE", "F", "C", NULL \
	}

typedef struct s_window
{
	void				*img;
	void				*mlx;
	void				*win;
	char				*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_window;

typedef struct s_map
{
	int					row_index;
	int					num_cols;
	char				*cols;
	struct s_map		*up;
	struct s_map		*down;
}						t_map;

typedef struct s_texture
{
	enum
	{
		NO,
		SO,
		EA,
		WE
	} type;
	int					width;
	int					height;
	int					**text_arr;
}						t_texture;

typedef struct s_configs
{
	struct s_texture	textures[4];
	int					floor_color[3];
	int					ceiling_color[3];
}						t_configs;

typedef struct s_main_data
{
	char				*pwd;
	struct s_window		wind;
	struct s_configs	conf;
	struct s_map		*map;
}						t_main_data;

int						init_configs(t_main_data *md, char *conf_path);
int						arr_len(char **arr);
int						is_map_symb(char symb);
int						is_config(char *str);
int						check_line(char *line, t_main_data *md, int fd);
int						valid_texture(int fd, int width, int height);
int						is_colors(char **colors);
int						valid_path(char *path, char *dir);
int						check_ext(char *file, char *ext);
int						check_row(char *row);
int						check_map(t_main_data *md);
int						valid_border(t_map *map, int i);
void					free_arr(char **arr);
void					add_to_str(char **str_add, int size, char *str);
void					skip_char(char *str, int *i, char c);
void					skip_line(int fd, int num_lines);
void					get_size(int fd, int *width, int *height);
void					add_node(t_map **map, t_map *node);
void					add_texture(t_main_data *md, char *path, int texture);
void					add_color(char *type, char *color, t_main_data *md);
void					free_int_arr(int **arr, int height);
void					free_map(t_map *map);
void					destroy_main_data(t_main_data *md);
long long int			ft_atoil(const char *str);
int						**init_text_arr(int fd, int width, int height);
t_map					*new_node(char *cols);

#endif