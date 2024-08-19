
NAME = cub3d

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L. -lmlx -framework OpenGL -framework AppKit

SRCS = src/gnl/get_next_line.c \
       src/gnl/get_next_line_utils.c \
       src/main.c \
	   src/parsing/parsing.c \
	   src/parsing/parsing_data.c \
	   src/parsing/c_colors_parsing.c \
	   src/parsing/f_colors_parsing.c \
	   src/utils/libft_utils.c \
	   src/utils/parsing_utils.c \

OBJ_DIR = objects

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME) $(FT_PRINTF)
	@echo "\n\033[1;32mCompilation complete.\033[0m"

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re