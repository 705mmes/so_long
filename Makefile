# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smunio <smunio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 08:48:44 by sammeuss          #+#    #+#              #
#    Updated: 2023/07/03 15:16:54 by smunio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     ███▄ ▄███▓ ▄▄▄       ██ ▄█▀▓█████   █████▒██▓ ██▓    ▓█████ 
#    ▓██▒▀█▀ ██▒▒████▄     ██▄█▒ ▓█   ▀ ▓██   ▒▓██▒▓██▒    ▓█   ▀ 
#    ▓██    ▓██░▒██  ▀█▄  ▓███▄░ ▒███   ▒████ ░▒██▒▒██░    ▒███   
#    ▒██    ▒██ ░██▄▄▄▄██ ▓██ █▄ ▒▓█  ▄ ░▓█▒  ░░██░▒██░    ▒▓█  ▄ 
#    ▒██▒   ░██▒ ▓█   ▓██▒▒██▒ █▄░▒████▒░▒█░   ░██░░██████▒░▒████▒
#    ░ ▒░   ░  ░ ▒▒   ▓▒█░▒ ▒▒ ▓▒░░ ▒░ ░ ▒ ░   ░▓  ░ ▒░▓  ░░░ ▒░ ░
#    ░  ░      ░  ▒   ▒▒ ░░ ░▒ ▒░ ░ ░  ░ ░      ▒ ░░ ░ ▒  ░ ░ ░  ░
#    ░      ░     ░   ▒   ░ ░░ ░    ░    ░ ░    ▒ ░  ░ ░      ░   
#           ░         ░  ░░  ░      ░  ░        ░      ░  ░   ░  ░
                                                            
NAME 			= so_long
PRINT_NAME		= so_long
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

SRC = 		so_long \
			free \
			draw \
			parsing \
			utils \
			runnin \
			map_parsing_0 \
			map_parsing_1 \
			map_is_possible \
			get_next_line \
			get_next_line_utils \
			init_game_and_textures \
			

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_DIR	= inc/libft/
MLX_DIR		= inc/mlx/build/
DIR_SRCS    = src/
DIR_OBJS    = objs/

SRCS        = $(addprefix $(DIR_SRCS), $(addsuffix .c, $(SRC)))
OBJS        = $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m\n"
		@make -C inc/libft
		@make -C inc/libft bonus
		@cmake inc/mlx -B inc/mlx/build
		@cmake --build inc/mlx/build -j4
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx42.a -Iinclude -lglfw -L"/Users/smunio/.brew/Cellar/glfw/3.3.8/lib/"
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling Done \033[0m\n"

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c $(OBJF)
				@mkdir -p $(DIR_OBJS)
				@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
		@rm -f $(OBJS)
		@make -C inc/libft/ clean
		@rm -r $(DIR_OBJS)
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
