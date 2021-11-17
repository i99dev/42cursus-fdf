# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 16:41:02 by oal-tena          #+#    #+#              #
#    Updated: 2021/11/14 16:41:02 by oal-tena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=fdf
SYSTEM=linux #

SRC=  	src/main.c	\
		tools/ft_colors.c

MINILIBX_PATH=mlx_linux

OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror
CC=gcc



$(OBJ_DIR)%.o:%.c src/fdf.h
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/tools
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -I/usr/include -I$(MINILIBX_PATH) -O3 -c $< -o $@

$(NAME):$(OBJ_PREFX)
	@gcc $(OBJ_PREFX) -L$(MINILIBX_PATH) -l$(MINILIBX_PATH) -L/usr/lib -I$(MINILIBX_PATH) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "make done !"


all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: 
	rm -f $(NAME)

re: fclean clean all
