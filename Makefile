NAME = cub3D
 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
 
SRC_DIR = src
MLX_DIR = minilibx-linux
 
SOURCES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/parsing/check_file.c \
			$(SRC_DIR)/parsing/takes_info.c \
			$(SRC_DIR)/parsing/parsing.c \
			$(SRC_DIR)/parsing/tools.c \
			$(SRC_DIR)/gnl/get_next_line.c \
			$(SRC_DIR)/gnl/get_next_line_utils.c \
			$(SRC_DIR)/raycasting/raycasting_core.c \
			$(SRC_DIR)/raycasting/raycasting.c \
			$(SRC_DIR)/raycasting/mlx_engine.c \
			$(SRC_DIR)/raycasting/renderer.c \
			$(SRC_DIR)/raycasting/input.c \
			$(SRC_DIR)/raycasting/movement.c
#			$(SRC_DIR)/parsing/init_struct.c   # à décommenter quand il aura du code
 
OBJECTS = $(SOURCES:.c=.o)
 
HEADERS = $(wildcard headers/*.h)
 
LIBFT = libft/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a
 
INCLUDES = -Iheaders -Ilibft -I$(MLX_DIR)
 
LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
 
 
all: $(NAME)
 
$(NAME): $(OBJECTS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LIBS) -o $(NAME)
 
$(LIBFT):
	make -C libft
 
$(MLX_LIB):
	make -C $(MLX_DIR)
 
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