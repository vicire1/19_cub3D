# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 16:53:35 by vdecleir          #+#    #+#              #
#    Updated: 2024/08/20 15:52:33 by vdecleir         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -Imlx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	src/main.c \
		src/init_mlx.c \
		src/utils/utils_mlx.c

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
	@echo "$(ORANGE)Compiling Minishell...$(CLOSE)"
	@$(CC) $(OBJS)  -L$(PRINTF_PATH) -lftprintf $(MLXFLAGS) -o $(NAME) $(LIBS)
	@echo "$(GREEN_BOLD)The Minishell executable is ready.$(CLOSE)"

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