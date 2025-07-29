/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:42:54 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/14 16:22:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*retptr;
	char	chr;

	chr = ch;
	retptr = NULL;
	while (*str)
	{
		if (*str == chr)
			retptr = (char *)str;
		str++;
	}
	if (*str == ch)
		retptr = (char *)str;
	return (retptr);
}
