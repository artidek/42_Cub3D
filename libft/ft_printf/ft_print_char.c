/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 07:38:00 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/07 23:33:38 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags)
{
	if (flags.width > 0)
		flags.width -= 1;
	return (flags);
}

static int	size(t_flags flags)
{
	int	len;
	int	sz;

	len = 1;
	sz = len;
	if (flags.width > 0)
		sz = len + flags.width;
	return (sz);
}

static void	set_str(char *result, t_flags flags, int sz, char args)
{
	char	*temp;

	temp = result;
	if (flags.width && !flags.minus)
	{
		memset(result, ' ', sz - 1);
		temp += sz - 1;
		*temp = (char)args;
	}
	if (flags.width && flags.minus)
	{
		temp[0] = (char)args;
		temp++;
		memset(temp, ' ', sz - 1);
	}
}

void	ft_print_char(t_flags flags, char args, t_list *cargs, t_list *sizes)
{
	t_flags	o_flags;
	char	*result;
	int		sz;
	int		*sptr;

	o_flags = override_flags(flags);
	sptr = malloc(sizeof(int));
	if (!sptr)
		return ;
	sz = size(o_flags);
	*sptr = sz;
	result = calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return ;
	if (!o_flags.width)
		result[0] = (char)args;
	set_str(result, o_flags, sz, args);
	ft_lstadd_back(&cargs, ft_lstnew(result));
	ft_lstadd_back(&sizes, ft_lstnew(sptr));
}
