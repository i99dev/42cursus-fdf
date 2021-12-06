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

# Color for terminel 
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

SRC=  	bre_line.c				\
		tools/ft_window.c		\
		tools/get_next_line.c	\
		tools/ft_hook.c			\
		tools/utils.c		\
		src/fdf.c


# path folodr
MINILIBX_PATH=lib/mlx_linux
MINILIBX_MACOS=lib/macos
LIBFT_PATH=lib/libft

# libarey
LIBFT=./lib/libft/libft.a
MLX=./lib/mlx_linux/libmlx_linux.a
MACOS=./lib/macos/libmlx.a


OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror
CC=gcc -g -O0

# for linux system uncomment the following line
# ################################################################
# $(OBJ_DIR)%.o:%.c include/fdf.h
# 	@mkdir -p $(OBJ_DIR)/src
# 	@mkdir -p $(OBJ_DIR)/tools
# 	@echo "Compiling: $<"
# 	@$(CC) $(CC_FLAGS) -I/usr/include -I$(MINILIBX_PATH) -O3 -c $< -o $@

# $(NAME):$(OBJ_PREFX) $(LIBFT) $(MLX)
# 	@$(CC) $(OBJ_PREFX) -L/usr/lib $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)
# 	@echo "make done !"



# for mac system uncomment the following line
# ################################################################
$(OBJ_DIR)%.o:%.c include/fdf.h
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/tools
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -I/usr/include -I$(MINILIBX_MACOS) -c $< -o $@

$(NAME):$(LIBFT) $(OBJ_PREFX) $(MACOS)
	$(CC)  $(OBJ_PREFX) $(MACOS) $(LIBFT)  -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make done !"
$(MACOS):
	@ $(MAKE) -C $(MINILIBX_MACOS)



$(LIBFT):
	@ $(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ echo "$(_INFO) libft.a removed.\n"
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ echo "$(_INFO) libft removed.\n"


fclean: 
	rm -f $(NAME)

re: fclean clean all
