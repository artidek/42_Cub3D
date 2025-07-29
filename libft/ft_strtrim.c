/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:00:38 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/13 19:12:22 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	char const	*temp;
	int			count;

	count = 0;
	while (*s1)
	{
		temp = set;
		while (*temp)
		{
			if (*s1 == *temp)
				break ;
			temp++;
		}
		if (*temp == '\0')
			break ;
		s1++;
		count++;
	}
	return (count);
}

static int	ft_end(char const *s1, char const *set, int len, int start)
{
	char const	*temp;
	int			strt;

	strt = len - 1;
	while (strt > start)
	{
		temp = set;
		while (*temp)
		{
			if (*temp == s1[strt])
				break ;
			temp++;
		}
		if (*temp == '\0')
			break ;
		strt--;
	}
	return (strt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strt;
	int		end;
	int		len;
	char	*trstr;
	char	*temp;

	len = ft_strlen((char *)s1);
	strt = ft_start(s1, set);
	end = ft_end(s1, set, len, strt);
	trstr = malloc(sizeof(char) * (end - strt) + 2);
	if (trstr == NULL)
		return (NULL);
	temp = trstr;
	while (strt <= end)
	{
		*temp++ = s1[strt];
		strt++;
	}
	*temp = '\0';
	return (trstr);
}
