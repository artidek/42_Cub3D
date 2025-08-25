/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:13 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/25 17:05:53 by aobshatk         ###   ########.fr       */
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
# define MAP_SYMB "NWSE01 	"
# define HEIGHT 768
# define WIDTH 1024
# define NUM_RAYS WIDTH
# define R_SPEED 0.027777778 //result of calculation 2.0 * (1 / 90) where 2.0 are deegress and 1 / 90 is a value of 1 degree in coord
# define SPEED 0.15

typedef enum e_keys
{
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	LEFT = 65361,
	RIGHT = 65363
}						t_key_values;

typedef enum e_type
{
	NO,
	SO,
	EA,
	WE
}						t_type;

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
	enum e_type			type;
	int					width;
	int					height;
	int					*text_arr;
}						t_texture;

typedef struct s_configs
{
	struct s_texture	textures[4];
	int					floor_color;
	int					ceiling_color;
}						t_configs;

typedef struct s_pos
{
	char				orientation;
	float				ia;
	float				pa;
	float				ra;
	float				x;
	float				y;
	float				wall_x;
	t_map				*row;
	int					col;
}						t_pos;

typedef struct s_main_data
{
	char				*pwd;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				ray_dirx;
	double				ray_diry;
	double				camera_x;
	double				side_dist_x;
	double				sidi_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					draw_start;
	int					draw_end;
	int					map_x;
	int					map_y;
	int					tex_x;
	int					tex_y;
	int					grid_size[2];
	int					cell_size[2];
	int					**grid;
	int					front_col;
	int					back_col;
	int					left_col;
	int					right_col;
	int					turn_key;
	int					color_int[3];
	int					line_height;
	float				grid_cell[2];
	struct s_window		wind;
	struct s_configs	conf;
	struct s_map		*map;
	struct s_pos		position;
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
int						locate_player(t_map *map, t_map **y, int *x,
							char *player);
int						no_path(t_map *y);
int						start_window(t_main_data *md);
int						build_grid(t_main_data *md);
int						collision(float ray_x, float ray_y, t_main_data *md);
int						cast_vert(t_main_data *md);
int						cast_hor(t_main_data *md);
int						valid_walls(t_map *map);
unsigned int			color(int color[3]);
float					get_x(t_main_data *md, int key);
float					ft_round(float val);
void					get_grid_coord(t_main_data *md);
void					parse_path(t_map *y, int x);
void					free_arr(char **arr);
void					add_to_str(char **str_add, int size, char *str);
void					skip_char(char *str, int *i, char *c);
void					skip_line(int fd, int num_lines);
void					get_size(int fd, int *width, int *height);
void					add_node(t_map **map, t_map *node);
void					add_texture(t_main_data *md, char *path, int texture);
void					add_color(char *type, char *color, t_main_data *md);
void					free_int_arr(int **arr, int height);
void					free_map(t_map *map);
void					destroy_main_data(t_main_data *md);
void					destroy_window(t_window wind);
void					draw_map(t_main_data *md);
void					move(int key_code, t_main_data *md);
void					orientation(int key_code, t_main_data *md);
void					redisplay(t_main_data *md);
void					render(int x, int y, t_main_data *md, int col);
void					set_initial_orientation(t_main_data *md);
void					down_left(t_main_data *md, float cx, float cy);
void					up_left(t_main_data *md, float cx, float cy);
void					up_right(t_main_data *md, float cx, float cy);
void					down_right(t_main_data *md, float cx, float cy);
void					cast_rays(t_main_data *md);
void					draw_object(t_main_data *md);
void					get_delta_dist(t_main_data *md);
void					check_walls(t_map *map, int i);
long long int			ft_atoil(const char *str);
int						*init_text_arr(int fd, int width, int height);
t_map					*new_node(char *cols);

#endif
