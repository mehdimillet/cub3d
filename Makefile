# Name = cub3d

# SRC_DIR = src
# SOURCE = 	$(SRC_DIR)/ main.c\
# 						parsing/check_file.c\

# OBJS_DIR = objs
# OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCE:.c=.o))

# CC = cc
# CFLAGS = -Wall -Werror -Wextra

# RM = rm -rf



# # MLX_DIR = minilibx-linux
# # MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# # MLX_INCLUDES = -I$(MLX_DIR)

# INCLUDES = -I$(SRC_DIR)

# GREEN = \033[1;32m
# RED = \033[1;31m
# RESET = \033[0m

# all: $(NAME)
# $(NAME): $(OBJECTS)
# # 	@make -C $(MLX_DIR)
# 	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

# $(OBJS_DIR)/%.o: %.cpp
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# 	@printf "$(GREEN)✔ Compilation terminée$(RESET)\n"

# clean:
# 	@$(RM) $(OBJS_DIR)
# # 	@make clean -C $(MLX_DIR)
# 	@printf "$(RED)✖ Fichiers objets supprimés.$(RESET)\n"

# fclean: clean
# 	@$(RM) $(NAME)
# # 	@make clean -C $(MLX_DIR)
# 	@printf "$(RED)✖ Fichiers objets supprimés.$(RESET)\n"

# re: fclean all

# # bonus : (je sais pas encore si bonus et ce qui faut mettre)
# .PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memillet <memillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 22:48:21 by memillet          #+#    #+#              #
#    Updated: 2025/11/29 22:18:38 by memillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES =	$(SRC_DIR)/main.c\
			$(SRC_DIR)/parsing/check_file.c\

SRC_DIR = src
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
CC = cc


# Chemins et flags pour MLX (Linux)


INCLUDES = -I$(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re