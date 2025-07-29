/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/07 13:56:11 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft.h"
# include <stdarg.h>

typedef struct t_flags
{
	int	minus;
	int	plus;
	int	blank;
	int	hash;
	int	zero;
	int	width;
	int	msize;
	int	sign;
}		t_flags;

int		ft_check_width(char **temp, int counter);
int		ft_fnd_frmtr(char *pos, char *formats);
t_flags	ft_set_width(t_flags flags, char *format);
int		ft_print_format(char **format);
t_flags	ft_set_flags(char *format);
void	ft_prt_arg(t_flags flags, va_list args, char *format, ...);
void	ft_print_str(t_flags flags, void *args, t_list *cargs, t_list *sizes);
void	ft_print_char(t_flags flags, char args, t_list *cargs, t_list *sizes);
void	ft_print_decimal(t_flags flags, int args, t_list *cargs, t_list *sizes);
char	*ft_utoa(unsigned int n);
void	ft_print_uint(t_flags flags, unsigned int args, t_list *cargs,
			t_list *sizes);
void	ft_print_x(t_flags flags, unsigned int args, t_list *cargs,
			t_list *sizes);
char	*ft_btoa(long long unsigned int n, char *base);
void	ft_print_cx(t_flags flags, unsigned int args, t_list *cargs,
			t_list *sizes);
void	ft_print_pointer(t_flags flags, void *args, t_list *cargs,
			t_list *sizes);
void	ft_print_hex(t_flags flags, char *conv, t_list *cargs, ...);
int		ft_printf(char *format, ...);
void	ft_print_digit(t_flags flags, char *conv, t_list *cargs, t_list *sizes);
#endif
