# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelen <khelen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 14:09:21 by khelen            #+#    #+#              #
#    Updated: 2020/08/09 14:13:21 by khelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -O3
LIBRARIES	= -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES	= -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT		= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fractal.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = main.c print.c extra.c mandelbrot.c julia.c errors.c hook_n_zoom.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS)  $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME) ||:
	@echo "\n┌─────────┬──┐"
	@echo "│  libft  │\033[1;32mOK\033[m│"
	@echo "├─────────┼──┼"
	@echo "│minilibx │\033[1;32mOK\033[m│"
	@echo "├─────────┼──┼"
	@echo "│ $(NAME) │\033[1;32mOK\033[m│"
	@echo "└─────────┴──┘"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY) ||:

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@ ||:
	@echo ".\c"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY) ||:

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) ||:

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean ||:
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean ||:
	@rm -rf $(OBJECTS_DIRECTORY) ||:

fclean: clean
	@rm -f $(MINILIBX) ||:
	@rm -f $(LIBFT) ||:
	@rm -f $(NAME) ||:
	@echo "┌──────────────────────┐"
	@echo "│\033[1;31mEverything was deleted\033[m│"
	@echo "└──────────────────────┘"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re