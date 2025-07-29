/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:22:49 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/20 14:57:16 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nstr(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s != '\0')
			s++;
	}
	return (len);
}

static void	free_spltd(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*fill_itm(const char *s, int len)
{
	char	*res;
	char	*temp;

	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	temp = res;
	while (*s != '\0' && len > 0)
	{
		*temp++ = *s++;
		len--;
	}
	*temp = '\0';
	return (res);
}

static int	insert_item(const char *s, char c, char **arr, int arr_pos)
{
	const char	*start;
	int			pos;
	int			len;

	pos = 0;
	len = 0;
	while (*s == c && c != 0)
	{
		s++;
		pos++;
	}
	start = s;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	arr[arr_pos] = fill_itm(start, len);
	if (arr[arr_pos] == NULL)
	{
		free_spltd(arr);
		return (0);
	}
	return (pos + len);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**spltd;
	int		i;
	int		pos;

	size = nstr(s, c);
	i = 0;
	pos = 0;
	if (size == 0)
		spltd = (char **)malloc(sizeof(char *));
	if (size > 0)
		spltd = (char **)malloc(sizeof(char *) * (size + 1));
	if (spltd == NULL)
		return (NULL);
	while (i < size)
	{
		pos = insert_item(s, c, spltd, i);
		if (pos == 0)
			return (NULL);
		s += pos;
		i++;
	}
	spltd[size] = NULL;
	return (spltd);
}
