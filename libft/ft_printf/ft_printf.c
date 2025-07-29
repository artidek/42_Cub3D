/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:53:07 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/07 23:35:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size(t_list *sizes)
{
	int	size;
	int	*ptr;

	size = 0;
	if (sizes->content != NULL)
	{
		ptr = sizes->content;
		size = *ptr;
	}
	return (size);
}

static int	print_result(char *format, t_list *args, t_list *sizes)
{
	int		len;
	int		move;
	char	*content;

	content = NULL;
	len = 0;
	if (!args)
		return (0);
	while (*format)
	{
		move = ft_fnd_frmtr(format, "cspdiuxX");
		if (move > 0)
		{
			args = args->next;
			sizes = sizes->next;
			if (args->content != NULL)
				content = (char *)args->content;
			len += size(sizes);
			write(1, content, size(sizes));
			format += (move + 1);
		}
		else
			len += ft_print_format(&format);
	}
	return (len);
}

static void	del(void *ptr)
{
	if (ptr)
	{
		free((char *)ptr);
	}
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	t_list	*sizes;
	int		move;
	int		len;
	t_list	*carg;

	len = 0;
	carg = ft_lstnew(NULL);
	sizes = ft_lstnew(NULL);
	va_start(args, format);
	while (format[len])
	{
		move = ft_fnd_frmtr(&format[len], "cspdiuxX");
		if (move > 0)
			ft_prt_arg(ft_set_flags(&format[len + 1]), args, &format[len
				+ move], carg, sizes);
		len += (move + 1);
	}
	va_end(args);
	len = print_result(format, carg, sizes);
	ft_lstclear(&carg, del);
	ft_lstclear(&sizes, del);
	return (len);
}
