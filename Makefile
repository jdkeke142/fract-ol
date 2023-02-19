# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/02/19 17:38:55 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_BIN		:= bin
DIR_OBJ		:= build

NAME		:= $(DIR_BIN)/fract_ol

SRC			:= fract_ol.c colors.c graphics.c fractals.c controls.c controls_keyboard.c \
			controls_mouse.c controls_julia.c fractals_mandelbrot.c \
			fractals_julia.c fractals_tricorn.c \
			fractals_burningship.c
OBJ			:= $(addprefix $(DIR_OBJ)/,$(SRC:c=o))

LIBS_PATH	:= libs
MLX_PATH	:= $(LIBS_PATH)/mlx_linux
LIBFT_PATH	:= $(LIBS_PATH)/libft

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -I$(LIBFT_PATH)/include -I$(MLX_PATH) -Iinclude -Ofast
LDFLAGS		:= -L$(LIBFT_PATH)/bin -lft_stdio -lft_string -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz

GIT			:= git

MKDIR		:= mkdir -p

INIT_SUB	:= $(shell $(GIT) submodule init)
UPDATE_SUB	:= $(shell $(GIT) submodule update)
BUILD_MLX	:= $(shell $(MAKE) -C $(MLX_PATH))
BUILD_LIBTT	:= $(shell $(MAKE) -C $(LIBFT_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(DIR_OBJ)/%.o: %.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

vpath %.c src:src/controls:src/fractals
