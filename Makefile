# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:07:12 by root              #+#    #+#              #
#    Updated: 2025/01/22 16:22:25 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#
NAME = so_long
HEADER_PATH = so_long.h
SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), 00_main.c 01_map_read_and_load.c 02_map_error_check.c 03_map_access_check.c 04_parsing_utils.c 05_start_game.c 06_play_game.c 07_game_utils.c 08_free_clear_and_close.c)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a
#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#
C_COMP = cc

FLAGS = -Wall -Werror -Wextra
FLAGS += -g -Imlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

RM = rm -f

AR = ar rcs

MAKE = make
#==============================================================================#
#                                  COLORS                                      #
#==============================================================================#
RED		= "\033[0;31m"
GREEN		= "\033[0;32m"  
YELLOW		= "\033[0;33m" 
RESET		= "\033[0m"
#==============================================================================#
#                               RULES & DEPS                                   #
#==============================================================================#
all: $(MLX) $(LIBFT) $(NAME)

%.o: %.c 
	@$(C_COMP) $(FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	echo $(YELLOW) "Cloning MiniLibX..." $(RESET); \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)
#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) $(OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)

cleanall: clean
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) was deleted!" $(RESET)

fcleanall: cleanall fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re cleanall fcleanall
