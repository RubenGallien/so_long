# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:27:59 by rgallien          #+#    #+#              #
#    Updated: 2024/04/15 16:54:07 by rgallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBNAME = libft.a

SRC_DIR	= src
OBJ_DIR = obj

SRCS	=	main.c \
			parsing.c \
			parsing_aux.c \
			assets.c \
			windows.c \
			draw.c \
			events.c \
			design_tab.c \
			pathfinding.c \
			pathfinding_utils.c \
			so_long_utils.c \
			land.c \
			land_2.c \
			land_3.c \
			land_4.c \
			land_5.c \
			draw_aux.c \
			move.c \
			assets_aux.c \
			move_aux.c \
			animations.c \

SRCS	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I include -I libft/include -I/usr/include -Imlx_linux -O3 -g3

RM			= rm -f
RMDIR		= rmdir
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all:	$(NAME)

$(NAME): $(OBJS)
	@if [ ! -e "$(LIBNAME)" ]; then \
		make -C libft ; \
		mv libft/libft.a . ;\
	fi
	$(CC) $(OBJS) $(LIBNAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJS); \
		$(RMDIR) $(OBJ_DIR); \
		make clean -C libft ; \
	fi

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBNAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:
