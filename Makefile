NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC_DIR = src

SOURCES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/parsing/check_file.c \
			$(SRC_DIR)/parsing/takes_info.c \
			$(SRC_DIR)/parsing/parsing.c \
			$(SRC_DIR)/parsing/tools.c \
			$(SRC_DIR)/gnl/get_next_line.c \
			$(SRC_DIR)/gnl/get_next_line_utils.c
#			$(SRC_DIR)/parsing/init_struct.c   # à décommenter quand il aura du code

OBJECTS = $(SOURCES:.c=.o)

HEADERS = $(wildcard headers/*.h)

LIBFT = libft/libft.a

INCLUDES = -Iheaders -Ilibft

# Pour le raycasting plus tard :
# MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm
# -> ajouter $(MLX) à la ligne de link, et "make -C minilibx-linux" comme pour la libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re