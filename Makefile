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
SYSTEM= lunix #linux or macos
SRC=  	main.c 		\

OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror

$(OBJ_DIR)%.o:%.c src/fdf.h
	@mkdir -p $(OBJ_DIR)/src
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

$(NAME):$(OBJ_PREFX)
	@gcc -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJ_PREFX)
	@echo "make done !"


all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: 
	rm -f $(NAME)

re: fclean clean all
