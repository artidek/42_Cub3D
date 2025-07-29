/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:47 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:05 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags, char *conv)
{
	if (flags.minus || flags.msize >= 0)
		flags.zero = 0;
	flags.width -= (int)ft_strlen(conv);
	if (flags.msize > (int)ft_strlen(conv))
		flags.width -= ((flags.msize - (int)ft_strlen(conv)));
	return (flags);
}

void	ft_print_x(t_flags flags, unsigned int args, t_list *cargs,
		t_list *sizes)
{
	char	*conv;
	t_flags	o_flags;

	conv = ft_btoa((unsigned int)args, "0123456789abcdef");
	o_flags = override_flags(flags, conv);
	if (conv[0] == '0' && o_flags.msize == 0)
	{
		o_flags = override_flags(flags, "");
		ft_print_hex(o_flags, "", cargs, "0x", sizes);
	}
	else
		ft_print_hex(o_flags, conv, cargs, "0x", sizes);
	free(conv);
}
