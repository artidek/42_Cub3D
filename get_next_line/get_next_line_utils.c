/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/09 21:34:08 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	char	cmp;

	cmp = ch;
	while (*str)
	{
		if (*str == cmp)
			return ((char *)str);
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}

void	realloc_line(char **r_line, char *buffer, int size)
{
	char	*temp;
	char	*copy;
	int		i;

	i = 0;
	temp = *r_line;
	copy = malloc(size + 1);
	if (!copy)
		return ;
	while (temp && *temp)
		copy[i++] = *temp++;
	while (*buffer)
		copy[i++] = *buffer++;
	copy[i] = '\0';
	free(*r_line);
	*r_line = copy;
}
