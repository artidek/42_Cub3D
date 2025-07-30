/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:35:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/30 21:34:00 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_colors(char **colors)
{
	int	i;
	long long int	color;

	i = 0;
	while (colors[i])
	{
		color = ft_atoil(colors[i]);
		if (is_number(colors[i]) && (color < 0 || color > 255))
			return (0);
		i++;
	}
	return (1);
}

int	is_config(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (CONFIGS[i])
	{
		if (len == ft_strlen(CONFIGS[i]) && ft_strncmp(str, CONFIGS[i],
				len) == 0)
				return (1);
		i++;
	}
	return (0);
}

int	is_map_symb(char symb)
{
	int		i;
	char	*symbols;

	i = 0;
	symbols = MAP_SYMB;
	while (symbols[i])
	{
		if (symbols[i] == symb)
			return (1);
		i++;
	}
	return (0);
}

int	check_ext(char *file, char *ext)
{
	char **spl_pth;
	char *trimmed;
	int len;

	trimmed = ft_strtrim(file, " ");
	spl_pth = ft_split(trimmed, '.');
	len = arr_len(spl_pth);
	if (spl_pth && (len < 2 || ft_strlen(spl_pth[len - 1]) != 3))
	{
		free_arr(spl_pth);
		free(trimmed);
		ft_printf("wrong file extention\n");
		return (0);
	}
	if (ft_strncmp(spl_pth[len - 1], ext, 3) != 0)
	{
		free_arr(spl_pth);
		free(trimmed);
		ft_printf("wrong file extention\n");
		return (0);
	}
	free_arr(spl_pth);
	free(trimmed);
	return (1);
}