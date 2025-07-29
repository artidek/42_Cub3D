/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:22:15 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 12:45:09 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	intsize(long long unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*insertnum(long long unsigned int n, size_t size, char *base)
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
	while (len >= 0)
	{
		if (n < 16)
		{
			strint[len] = base[n];
			break ;
		}
		strint[len] = base[n % 16];
		n = n / 16;
		len--;
	}
	strint[size] = '\0';
	return (strint);
}

char	*ft_btoa(long long unsigned int n, char *base)
{
	long long int	num;
	int				len;
	char			*result;

	len = 0;
	num = (long long unsigned int)n;
	len += intsize(num);
	result = insertnum(num, sizeof(char) * len, base);
	return (result);
}
