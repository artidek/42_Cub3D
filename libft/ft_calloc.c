/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:41:39 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/22 13:53:40 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*retptr;
	unsigned int	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (retptr = malloc(sizeof(unsigned char) * 1));
	if (nmemb == INT_MAX || size == INT_MAX || (int)nmemb < 0 || (int)size < 0)
	{
		write(1, "Memory allocation failed: ENOMEM\n", 30);
		return (NULL);
	}
	retptr = malloc(nmemb * size);
	while (i < nmemb * size)
	{
		retptr[i] = 0;
		i++;
	}
	return (retptr);
}
