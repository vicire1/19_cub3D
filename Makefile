# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 16:53:35 by vdecleir          #+#    #+#              #
#    Updated: 2024/08/27 15:45:20 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLOSE = \033[0m

NAME = cub3D

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror
FLAGS_OPTI = -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3
FLAGS_X86	= -Wall -Wextra -Werror -O3 -march=native
FLAGS_ARM	= -Wall -Wextra -Werror -O3 -arch arm64
MLXFLAGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRCS =	src/main.c \
		src/init_mlx.c \
		src/utils/utils_mlx.c \
		src/parsing/parsing.c \
		src/parsing/parsing_data.c \
		src/parsing/map_parsing.c \
		src/parsing/colors_parsing/c_colors_parsing.c \
		src/parsing/colors_parsing/f_colors_parsing.c \
		src/parsing/walls_parsing/wall_parsing.c \
		src/parsing/walls_parsing/wall_parsing_utils.c \
		src/utils/free_utils.c \
		src/utils/libft_utils.c \
		src/utils/parsing_utils.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \
		src/raycasting.c \
		src/moves.c \
		src/hooks.c \

OBJ_DIR = objets

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

MLX = libmlx.a

MLX_PATH = ./src/mlx

MLX_FLAG = $(MLX_PATH)/.libcompiled

PRINTF = libftprintf.a

PRINTF_PATH = ./src/ft_printf_fd

PRINTF_FLAG = $(PRINTF_PATH)/.libcompiled

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(FLAGS_OPTI) -c $< -o $@

all: architecture $(NAME)

architecture:
	@uname -m | grep -q 'arm' && FLAGS="$(FLAGS_ARM)" || FLAGS="$(FLAGS_X86)"

$(NAME): $(OBJS) $(PRINTF_FLAG) $(MLX_FLAG)
	@echo "$(ORANGE)Compiling cub3D...$(CLOSE)"
	@$(CC) $(OBJS)  -L$(PRINTF_PATH) -lftprintf $(MLXFLAGS) -o $(NAME) $(LIBS)
	@echo "$(GREEN_BOLD)The cub3D executable is ready.$(CLOSE)"

$(MLX_FLAG):
	@echo "$(ORANGE)Compiling MLX...$(CLOSE)"
	@make -s -C $(MLX_PATH)
	@echo "$(GREEN)MLX ready.$(CLOSE)"
	@touch $(MLX_FLAG)

$(PRINTF_FLAG):
	@echo "$(ORANGE)Compiling Ft_printf...$(CLOSE)"
	@make -s -C $(PRINTF_PATH)
	@echo "$(GREEN)Ft_printf ready.$(CLOSE)"
	@touch $(PRINTF_FLAG)

clean:
	@$(MAKE) clean -s -C $(PRINTF_PATH)
	@$(MAKE) clean -s -C $(MLX_PATH)
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)Objects correctly deleted.$(CLOSE)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PRINTF_PATH)/$(PRINTF) $(PRINTF_FLAG)
	@$(RM) $(MLX_PATH)/$(MLX) $(MLX_FLAG)
	@echo "$(YELLOW)Executable file(s) correctly deleted.$(CLOSE)"

re: fclean all

.PHONY: all clean fclean re