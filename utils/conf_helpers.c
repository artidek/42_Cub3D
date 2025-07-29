/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:35:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/07/29 22:02:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_ext(char *file, char *ext)
{
	char **spl_pth;
	char *trimmed;
	int len;

	trimmed = ft_strtrim(file, " ");
	spl_pth = ft_split(trimmed, '.');
	len = arr_len(spl_pth);
	if (spl_pth && (len < 2 || ft_strlen(spl_pth[len - 1] != 3)))
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