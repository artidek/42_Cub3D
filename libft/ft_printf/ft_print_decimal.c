/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:15:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 23:29:52 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags, char *conv, int args)
{
	if (flags.minus || flags.msize >= 0)
		flags.zero = 0;
	if (args < 0)
	{
		flags.blank = 0;
		flags.plus = 0;
		flags.sign = 45;
	}
	if (flags.plus)
	{
		flags.blank = 0;
		flags.sign = 43;
	}
	if (flags.blank)
		flags.sign = 32;
	if (flags.sign)
		flags.width--;
	flags.width -= (int)ft_strlen(conv);
	if (flags.msize > (int)ft_strlen(conv))
		flags.width -= ((flags.msize - (int)ft_strlen(conv)));
	return (flags);
}

void	ft_print_decimal(t_flags flags, int args, t_list *cargs, t_list *sizes)
{
	char	*conv;
	t_flags	o_flags;

	conv = ft_itoa((int)args);
	o_flags = override_flags(flags, conv, (int)args);
	if (conv[0] == '0' && o_flags.msize == 0)
	{
		o_flags = override_flags(flags, "", (int)args);
		ft_print_digit(o_flags, "", cargs, sizes);
	}
	else if (conv[0] == '-')
	{
		o_flags = override_flags(flags, &conv[1], (int)args);
		ft_print_digit(o_flags, &conv[1], cargs, sizes);
	}
	else
		ft_print_digit(o_flags, conv, cargs, sizes);
	free(conv);
}
