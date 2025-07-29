/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:04:26 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/22 13:55:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*temdup;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		write(1, "Memory allocation failed: ENOMEM\n", 30);
		return (NULL);
	}
	temdup = dup;
	while (*s)
		*temdup++ = *s++;
	*temdup = '\0';
	return (dup);
}
