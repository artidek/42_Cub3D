/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnd_frmtr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:27:46 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/04 19:21:45 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_fnd_frmtr(char *pos, char *formats)
{
	char	*temp;
	int		counter;

	counter = 0;
	temp = pos + 1;
	if (*pos == '%' && *temp != '%')
	{
		while (*temp == ' ' || *temp == '-' || *temp == '+' || *temp == '#'
			|| *temp == '0')
		{
			counter++;
			temp++;
		}
		counter = ft_check_width(&temp, counter);
		while (*formats)
		{
			if (*temp == *formats)
				return (counter += 1);
			formats++;
		}
	}
	return (0);
}
