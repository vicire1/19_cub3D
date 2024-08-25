# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 16:53:35 by vdecleir          #+#    #+#              #
#    Updated: 2024/08/25 18:53:58 by vdecleir         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -Imlx -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

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

OBJ_DIR = objets

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

PRINTF = libftprintf.a

PRINTF_PATH = ./src/ft_printf_fd

PRINTF_FLAG = $(PRINTF_PATH)/.libcompiled

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_FLAG)
	@echo "$(ORANGE)Compiling cub3D...$(CLOSE)"
	@$(CC) $(OBJS)  -L$(PRINTF_PATH) -lftprintf $(MLXFLAGS) -o $(NAME) $(LIBS)
	@echo "$(GREEN_BOLD)The cub3D executable is ready.$(CLOSE)"

$(PRINTF_FLAG):
	@echo "$(ORANGE)Compiling Ft_printf...$(CLOSE)"
	@make -s -C $(PRINTF_PATH)
	@echo "$(GREEN)Ft_printf ready.$(CLOSE)"
	@touch $(PRINTF_FLAG)

clean:
	@$(MAKE) clean -s -C $(PRINTF_PATH)
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)Objects correctly deleted.$(CLOSE)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PRINTF_PATH)/$(PRINTF) $(PRINTF_FLAG)
	@echo "$(YELLOW)Executable file(s) correctly deleted.$(CLOSE)"

re: fclean all

.PHONY: all clean fclean re