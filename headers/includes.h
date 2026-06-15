#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
// # include "minilibx-linux/mlx.h"

//check_file.c
int	check_filename(char *map_name);
int	count_line(int fd);

//takes_info.c
char	**read_file(int fd, int nbline);
int	get_fd(char *file);

//parsing.c
int start(char **av);

// tools.c
int	ft_strcmp(char *s1, char *s2);

#endif 