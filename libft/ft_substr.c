/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:50:38 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/20 16:03:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aloc_mem(size_t size)
{
	char	*str;

	str = malloc(size);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;

	if (start > ft_strlen(s) - 1)
	{
		substr = aloc_mem(1);
		*substr = '\0';
		return (substr);
	}
	if (ft_strlen(s) < len || start == ft_strlen(s) - 1)
		len = ft_strlen(s) - (size_t)start;
	if (len > UINT_MAX || len == 0)
		substr = aloc_mem(sizeof(char) * 1);
	if (len < UINT_MAX && len > 0)
		substr = aloc_mem(sizeof(char) * len + 1);
	temp = substr;
	while (s[start] && len > 0)
	{
		*temp++ = s[start];
		len--;
		start++;
	}
	*temp = '\0';
	return (substr);
}
