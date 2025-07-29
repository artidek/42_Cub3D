/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:35:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 19:43:07 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_format(char **format)
{
	char	*cmpfrmt;
	int		len;

	cmpfrmt = (*format) + 1;
	len = 0;
	if (**format == '%' && *cmpfrmt == '%')
	{
		write(1, *format, 1);
		len++;
		(*format) += 2;
	}
	if (**format == '%' && *cmpfrmt != '%')
	{
		write(1, *format, 1);
		len++;
		(*format)++;
	}
	while (**format != '%' && **format)
	{
		write(1, *format, 1);
		len++;
		(*format)++;
	}
	return (len);
}
