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

# Color for terminel 
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

SRC=  	src/main.c	\
		tools/ft_colors.c
# path folodr
MINILIBX_PATH=lib/mlx_linux
LIBFT_PATH=lib/libft

# libarey
LIBFT=./lib/libft/libft.a
MLX=./lib/mlx_linux/libmlx_linux.a


OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror
CC=gcc

# for linux system uncomment the following line
# ################################################################
$(OBJ_DIR)%.o:%.c include/fdf.h
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/tools
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -I/usr/include -I$(MINILIBX_PATH) -O3 -c $< -o $@

$(NAME):$(OBJ_PREFX) $(MLX) $(LIBFT)
	@gcc $(OBJ_PREFX) -L/usr/lib $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "make done !"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@ $(MAKE) -C $(MINILIBX_PATH)


# for mac system uncomment the following line
# ################################################################
# $(OBJ_DIR)%.o:%.c src/fdf.h
# 	@mkdir -p $(OBJ_DIR)/src
# 	@mkdir -p $(OBJ_DIR)/tools
# 	@echo "Compiling: $<"
# 	@gcc $(CC_FLAGS) -I/usr/include -I$(MINILIBX_PATH) -c $< -o $@

# $(NAME):$(OBJ_PREFX)
# 	@gcc $(OBJ_PREFX) -L$(MINILIBX_PATH) -l$(MINILIBX_PATH) -framework OpenGL -framework AppKit -o $(NAME)
# 	@echo "make done !"



all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ echo "$(_INFO) libft.a removed.\n"
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ echo "$(_INFO) libft removed.\n"
	@ $(MAKE) clean -C $(MINILIBX_PATH)
	@ echo "$(_INFO) MLX removed.\n"


fclean: 
	rm -f $(NAME)

re: fclean clean all
