/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:46:12 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/05 21:23:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	num_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

t_flags	ft_set_width(t_flags flags, char *format)
{
	int	num;

	num = 0;
	if (*format > 48 && *format <= 57)
	{
		num = ft_atoi((const char *)format);
		flags.width = num;
		format += num_len(num);
	}
	if (*format == '.')
	{
		flags.msize = 0;
		format++;
		if (*format >= 48 && *format <= 57)
		{
			num = ft_atoi((const char *)format);
			flags.msize = num;
			format += num_len(num);
		}
	}
	return (flags);
}
