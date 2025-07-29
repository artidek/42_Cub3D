/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:22:15 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/13 18:27:55 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intsize(long long int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*insertnum(long long int n, int sign, size_t size)
{
	int		len;
	char	*strint;

	len = size - 2;
	strint = NULL;
	strint = malloc(size);
	if (strint == NULL)
		return (NULL);
	if (sign)
		strint[0] = '-';
	if (len == 0)
		strint[len] = n % 10 + 48;
	while (len >= 0 && n > 0)
	{
		strint[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	strint[size - 1] = '\0';
	return (strint);
}

char	*ft_itoa(int n)
{
	long long int	num;
	int				neg;
	int				len;

	neg = 0;
	len = 0;
	if (n < 0)
	{
		num = -(long long int)n;
		neg = 1;
		len++;
	}
	else
	{
		num = n;
	}
	len += intsize(num);
	if (n == 0)
		len += 1;
	return (insertnum(num, neg, sizeof(char) * len + 1));
}
