# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:00:05 by aobshatk          #+#    #+#              #
#    Updated: 2025/04/07 13:51:27 by aobshatk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_check_width.c ft_fnd_frmtr.c ft_set_width.c \
				  ft_print_format.c ft_set_flags.c ft_prt_arg.c \
				  ft_print_str.c ft_print_char.c ft_print_decimal.c \
				  ft_utoa.c ft_print_uint.c ft_print_x.c \
				  ft_btoa.c ft_print_cx.c ft_print_pointer.c \
				  ft_printf.c ft_print_hex.c ft_print_digit.c

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

LIBFTPATH		= ../
LIBFT			= $(LIBFTPATH)/libft.a

NAME			= libftprintf.a

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:			
	make -C $(LIBFTPATH) clean
	$(RM) $(OBJS)

$(LIBFT):		
			make -C $(LIBFTPATH) bonus			

fclean:	
		make -C $(LIBFTPATH) fclean
		$(RM) $(OBJS)
		$(RM) $(NAME)
				
bonus: all

re:				fclean $(NAME)

.PHONY:			all clean fclean re
