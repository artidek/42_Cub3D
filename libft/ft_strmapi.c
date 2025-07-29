/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:53:09 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/13 18:40:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*resstr;
	int		len;
	int		i;

	resstr = NULL;
	len = 0;
	i = 0;
	while (s[len])
		len++;
	resstr = malloc(sizeof(char) * len + 1);
	if (resstr == NULL)
		return (NULL);
	while (i < len)
	{
		resstr[i] = f(i, s[i]);
		i++;
	}
	resstr[len] = '\0';
	return (resstr);
}
