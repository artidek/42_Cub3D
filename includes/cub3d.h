/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:13 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/29 22:02:48 by aobshatk         ###   ########.fr       */
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

typedef struct s_clist
{
	char				val;
	int					index;
	struct s_clist		*left;
	struct s_clist		*right;

}						t_clist;

typedef struct s_rlist
{
	char				val;
	struct s_clist		*cols;
	struct s_rlist		*up;
	struct s_rlist		*down;
}						t_rlist;

typedef struct s_configs
{
	int					*n_text;
	int					*s_text;
	int					*e_text;
	int					*w_text;
	int					floor_color[3];
	int					ceiling_color[3];
}						t_configs;

typedef struct s_main_data
{
	struct s_window		wind;
	struct s_configs	conf;
	struct s_rlist		*map;
}						t_main_data;

int						init_configs(t_main_data *md, char *conf_path);
int						arr_len(char **arr);
void					free_arr(char **arr);

#endif