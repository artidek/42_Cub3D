/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:30:10 by aobshatk          #+#    #+#             */
/*   Updated: 2025/09/02 11:40:29 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_color_vals(char *line)
{
	int i;
	char *trimmed;
	char *res;

	i = 1;
	res = NULL;
	trimmed = ft_strtrim(line, " 	\n");
	while (trimmed[i])
	{
		if (trimmed[i] != ' ' && trimmed[i] != '	')
			add_to_str(&res, 1, &trimmed[i]);
		i++;
	}
	free(trimmed);
	return (res);
}