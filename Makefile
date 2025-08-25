CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L/usr/X11/lib -L./minilibx
LDLIBS = -lmlx -lXext -lX11 -lm
SRCSPATH = ./src
UTILSPATH = ./utils
GNLPATH = ./get_next_line
PRINTFPATH = ./libft/ft_printf
MLXPATH = ./minilibx

SRCS = $(SRCSPATH)/init_conf.c $(SRCSPATH)/conf_checkers.c $(SRCSPATH)/map_parser.c $(SRCSPATH)/path_parser.c $(SRCSPATH)/window.c \
	   $(SRCSPATH)/motion.c $(SRCSPATH)/orientation.c $(SRCSPATH)/render.c $(SRCSPATH)/ray_caster.c $(SRCSPATH)/object_builder.c
UTILS = $(UTILSPATH)/conf_helpers.c $(UTILSPATH)/gen_helpers.c $(UTILSPATH)/data_destroyers.c $(UTILSPATH)/data_initializers.c $(UTILSPATH)/data_helpers.c \
		$(UTILSPATH)/map_utils.c  $(UTILSPATH)/math_helpers.c $(UTILSPATH)/grid.c $(UTILSPATH)/dda_helpers.c $(UTILSPATH)/border_parser.c
GNL = $(GNLPATH)/get_next_line.c $(GNLPATH)/get_next_line_utils.c

PRINTFA = $(PRINTFPATH)/libftprintf.a
MLXA = $(MLXPATH)/libmlx.a
LIBR = cub3d.a
NAME = cub3d

SRCOBJS = $(SRCS:.c=.o)
UTILSOBJS = $(UTILS:.c=.o)
GNLOBJS = $(GNL:.c=.o)
OBJS =$(GNLOBJS) $(UTILSOBJS) $(SRCOBJS)


%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.c $(LIBR)
		@$(CC) $(CFLAGS) $(LDFLAGS) main.c $(LIBR) -o $(NAME) $(LDLIBS)
		@echo "Build complete"

all: $(NAME)

$(PRINTFA):
			@make -s -C $(PRINTFPATH)

$(MLXA):
		@make -s -C $(MLXPATH)

$(LIBR): $(PRINTFA) $(MLXA) $(OBJS)
		@ar x $(PRINTFA)
		@ar x $(MLXA)
		@ar rcs $(LIBR) $(OBJS) *.o
		@rm -f *.o


clean:
		@rm -f $(OBJS)
		@make -s -C $(PRINTFPATH) clean
		@echo "Clean complete"

fclean:
		@rm -f $(OBJS)
		@rm -f $(NAME)
		@rm -f $(LIBR)
		@make -s -C $(PRINTFPATH) fclean
		@make -s -C $(MLXPATH) clean
		@echo "Clean complete"

re: fclean $(NAME)

.PHONY: all fclean clean re
