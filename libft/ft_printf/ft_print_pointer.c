/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:56:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/07 21:54:06 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags)
{
	flags.hash = 1;
	flags.zero = 0;
	return (flags);
}

static int	print_null(t_flags flags, char *args, t_list *cargs)
{
	int		len;
	int		sz;
	char	*result;

	len = (int)ft_strlen(args);
	sz = len;
	if (flags.width > len)
		sz = len + (flags.width - len);
	result = malloc(sizeof(char) * sz + 1);
	if (!result)
		return (0);
	ft_memset(result, 0, sz + 1);
	if (flags.minus)
	{
		ft_memmove(result, args, len);
		ft_memset(result + len, ' ', sz - len);
	}
	else
	{
		ft_memset(result, ' ', sz - len);
		ft_memmove(result + (sz - len), args, len);
	}
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

static int	set_args_te(t_flags flags, char *args, t_list *cargs)
{
	int		len;
	int		sz;
	char	*result;

	len = (int)ft_strlen(args) + 2;
	sz = len;
	if (flags.width > len)
		sz = len + (flags.width - len);
	result = malloc(sizeof(char) * sz + 1);
	if (!result)
		return (0);
	ft_memset(result, 0, sz + 1);
	ft_memmove(result, "0x", 2);
	ft_memmove(result + 2, args, len);
	ft_memset(result + len, ' ', sz - len);
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

static int	set_args_fs(t_flags flags, char *args, t_list *cargs)
{
	int		len;
	int		sz;
	char	*result;

	len = (int)ft_strlen(args) + 2;
	sz = len;
	if (flags.width > len)
		sz = len + (flags.width - len);
	result = malloc(sizeof(char) * sz + 1);
	if (!result)
		return (0);
	ft_memset(result, 0, sz + 1);
	ft_memset(result, ' ', sz - len);
	ft_memmove(result + (sz - len), "0x", 2);
	ft_memmove(result + (sz - len) + 2, args, len);
	ft_lstadd_back(&cargs, ft_lstnew(result));
	return (sz);
}

void	ft_print_pointer(t_flags flags, void *args, t_list *cargs,
		t_list *sizes)
{
	t_flags					o_flags;
	char					*sargs;
	long long unsigned int	dargs;
	int						*sz;

	o_flags = override_flags(flags);
	dargs = (long long unsigned int)args;
	sz = malloc(sizeof(int));
	if (!sz)
		return ;
	if (dargs == 0)
	{
		sargs = "(nil)";
		*sz = print_null(o_flags, sargs, cargs);
		ft_lstadd_back(&sizes, ft_lstnew(sz));
		return ;
	}
	else
		sargs = ft_btoa(dargs, "0123456789abcdef");
	if (flags.minus)
		*sz = set_args_te(o_flags, sargs, cargs);
	else
		*sz = set_args_fs(o_flags, sargs, cargs);
	ft_lstadd_back(&sizes, ft_lstnew(sz));
	free(sargs);
}
