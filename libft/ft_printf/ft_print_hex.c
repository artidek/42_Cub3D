/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:09:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/09 23:26:42 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size(char *args, t_flags flags)
{
	int	len;
	int	sz;

	len = (int)ft_strlen(args);
	if (flags.msize > len)
		len = flags.msize;
	sz = len;
	if (flags.width > 0)
		sz = len + flags.width;
	return (sz);
}

static char	*print_zero(t_flags flags, char *temp, int len)
{
	if (flags.hash && flags.width > 0)
		flags.width -= 2;
	if (flags.width > 0 && flags.zero)
	{
		memset(temp, '0', flags.width);
		temp += flags.width;
	}
	if (flags.msize > len)
	{
		memset(temp, '0', flags.msize - len);
		temp += flags.msize - len;
	}
	return (temp);
}

static int	set_args_te(t_flags flags, char *args, t_list *cargs, char *x)
{
	int		sz;
	char	*result;
	char	*temp;

	sz = size(args, flags);
	result = ft_calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return (0);
	temp = result;
	if (flags.hash)
	{
		memmove(temp, x, 2);
		temp += 2;
	}
	if (flags.zero || flags.msize > (int)ft_strlen(args))
		temp = print_zero(flags, temp, (int)ft_strlen(args));
	memmove(temp, args, (int)ft_strlen(args));
	temp += (int)ft_strlen(args);
	if (flags.width > 0 && !flags.zero)
	{
		memset(temp, ' ', flags.width);
		temp += flags.width;
	}
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

static int	set_args_fs(t_flags flags, char *args, t_list *cargs, char *x)
{
	int		sz;
	char	*result;
	char	*temp;

	sz = size(args, flags);
	result = ft_calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return (0);
	temp = result;
	if (flags.width > 0 && !flags.zero)
	{
		memset(temp, ' ', flags.width);
		temp += flags.width;
	}
	if (flags.hash)
	{
		memmove(temp, x, 2);
		temp += 2;
	}
	if (flags.zero || flags.msize > (int)ft_strlen(args))
		temp = print_zero(flags, temp, (int)ft_strlen(args));
	memmove(temp, args, (int)ft_strlen(args));
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

void	ft_print_hex(t_flags flags, char *conv, t_list *cargs, ...)
{
	int		*sz;
	char	*x;
	t_list	*sizes;
	va_list	args;

	va_start(args, cargs);
	x = (char *)va_arg(args, char *);
	sizes = (t_list *)va_arg(args, t_list *);
	va_end(args);
	sz = malloc(sizeof(int));
	if (!sz)
		return ;
	if (conv[0] == '0')
		flags.hash = 0;
	if (flags.minus)
		*sz = set_args_te(flags, conv, cargs, x);
	else
		*sz = set_args_fs(flags, conv, cargs, x);
	ft_lstadd_back(&sizes, ft_lstnew(sz));
}
