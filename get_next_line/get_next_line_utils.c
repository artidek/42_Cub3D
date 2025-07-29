/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/30 01:11:24 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}

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
		return (NULL);
	temdup = dup;
	while (*s)
		*temdup++ = *s++;
	*temdup = '\0';
	return (dup);
}

/*char	*ft_strchr(const char *str, int ch)
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
}*/

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
