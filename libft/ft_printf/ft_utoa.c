/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:22:15 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/31 09:58:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	intsize(long long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*insertnum(long long int n, size_t size)
{
	int		len;
	char	*strint;

	len = size - 1;
	strint = NULL;
	strint = malloc(size + 1);
	if (strint == NULL)
		return (NULL);
	if (n == 0)
		strint[len] = '0';
	while (len >= 0 && n > 0)
	{
		strint[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	strint[size] = '\0';
	return (strint);
}

char	*ft_utoa(unsigned int n)
{
	long long int	num;
	int				len;
	char			*result;

	len = 0;
	num = (long long int)n;
	len += intsize(num);
	result = insertnum(num, sizeof(char) * len);
	return (result);
}
