Name = cub3d

SRC_DIR = src
SOURCE = 	$(SRC_DIR)/main.c\

OBJS_DIR = objs
OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCE:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf



MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INCLUDES = -I$(MLX_DIR)

INCLUDES = -I$(SRC_DIR) $(MLX_INCLUDES)

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)
$(NAME): $(OBJECTS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)✔ Compilation terminée$(RESET)\n"

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -C $(MLX_DIR)
	@printf "$(RED)✖ Fichiers objets supprimés.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C $(MLX_DIR)
	@printf "$(RED)✖ Fichiers objets supprimés.$(RESET)\n"

re: fclean all

# bonus : (je sais pas encore si bonus et ce qui faut mettre)
.PHONY: all clean fclean re