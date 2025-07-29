/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/23 17:09:46 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*temph;
	size_t		i;
	size_t		a;
	size_t		needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen((char *)needle);
	if (len == 0)
		return (NULL);
	a = 0;
	while (a <= len - needle_len && haystack[a])
	{
		i = 0;
		temph = &haystack[a];
		while (i < needle_len && needle[i] == temph[i])
			i++;
		if (i == needle_len)
			return ((char *)&haystack[a]);
		a++;
	}
	return (NULL);
}
