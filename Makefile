# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:07:12 by root              #+#    #+#              #
#    Updated: 2025/01/13 20:29:26 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#
NAME = so_long.a 
HEADER_PATH = so_long.h
SRCS = teste.c
OBJS = $(SRCS:.c=.o)

EXEC_SRC = main.c
EXEC = so_long

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a
#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#
C_COMP = cc

FLAGS = -Wall -Werror -Wextra
FLAGS += -g -I mlx_linux
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
#                                  RULES                                       #
#==============================================================================#
all: $(NAME) exec

%.o: %.c 
	@$(C_COMP) $(FLAGS) $(MLX_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)

#==============================================================================#
#                                 EXEC & MLX                                   #
#==============================================================================#
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	echo $(YELLOW) "Cloning MiniLibX..." $(RESET); \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

 exec: $(MLX) $(LIBFT)
	@$(C_COMP) $(FLAGS) $(MLX_FLAGS) $(SRCS) $(EXEC_SRC) $(LIBFT) $(NAME) -L -lft -o $(EXEC)
	@echo $(GREEN) "$(EXEC) program was created successfully!"$(RESET)

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) -f $(OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)

fcleanlib:
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(NAME) $(EXEC)
	@echo $(RED) "$(NAME) and $(EXEC) were deleted!" $(RESET)

fcleanall: fcleanlib fclean

re: fclean all

.PHONY: all clean fclean re exec 