/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:39:54 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/23 19:15:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

int	arr_len(char **arr)
{
	int len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

void	add_to_str(char **str_add, int size, char *str)
{
	char	*temp;
	char	*temp_str;

	temp = NULL;
	if (!*str_add)
	{
		*str_add = malloc(sizeof(char) * size + 1);
		ft_strlcpy(*str_add, str, size + 1);
		return ;
	}
	temp = ft_strdup(*str_add);
	free(*str_add);
	temp_str = malloc(sizeof(char) * size + 1);
	ft_strlcpy(temp_str, str, size + 1);
	*str_add = ft_strjoin(temp, temp_str);
	free(temp_str);
	free(temp);
}

void skip_char(char *str, int *i, char *c)
{
	int	j;
	int	len;
	
	len = ft_strlen(c);
	while (str[*i])
	{
		j = len - 1;
		while (j >= 0)
		{
			if (str[*i] == c[j])
				break;
			j--;
		}
		if (j < 0)
			return;
		(*i)++;
	}
	
}

long long int	ft_atoil(const char *str)
{
	long long int	i;
	long long int	sign;

	i = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * sign);
}