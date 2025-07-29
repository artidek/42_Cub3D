/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:49 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/07 20:40:56 by aobshatk         ###   ########.fr       */
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
	if (flags.sign)
		sz++;
	return (sz);
}

static char	*print_zero(t_flags flags, char *temp, int len)
{
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

static int	set_args_te(t_flags flags, char *args, t_list *cargs)
{
	int		sz;
	char	*result;
	char	*temp;

	sz = size(args, flags);
	result = ft_calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return (0);
	temp = result;
	if (flags.sign)
	{
		memset(temp, flags.sign, 1);
		temp += 1;
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

static int	set_args_fs(t_flags flags, char *args, t_list *cargs)
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
	if (flags.sign)
	{
		memset(temp, flags.sign, 1);
		temp += 1;
	}
	if (flags.zero || flags.msize > (int)ft_strlen(args))
		temp = print_zero(flags, temp, (int)ft_strlen(args));
	memmove(temp, args, (int)ft_strlen(args));
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

void	ft_print_digit(t_flags flags, char *conv, t_list *cargs, t_list *sizes)
{
	int	*size;

	size = malloc(sizeof(int));
	if (!size)
		return ;
	if (flags.minus)
		*size = set_args_te(flags, conv, cargs);
	else
		*size = set_args_fs(flags, conv, cargs);
	ft_lstadd_back(&sizes, ft_lstnew(size));
}
