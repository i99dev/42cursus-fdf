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


SRC=  	src/main.c

MINILIBX_PATH=mlx_linux

OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror

$(OBJ_DIR)%.o:%.c src/fdf.h
	@mkdir -p $(OBJ_DIR)/src
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):$(OBJ_PREFX)
	@gcc -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit $(OBJ_PREFX) -o $(NAME)
	@echo "make done !"


all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: 
	rm -f $(NAME)

re: fclean clean all
