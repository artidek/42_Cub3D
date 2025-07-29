/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:12:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/18 16:01:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*temp;
	int		len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	jstr = malloc(sizeof(char) * len + 1);
	if (jstr == NULL)
		return (NULL);
	temp = jstr;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (jstr);
}
