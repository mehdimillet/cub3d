#ifndef INCLUDES_H
# define INCLUDES_H

# include "enum.h"
# include "player.h" 
# include "map.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "raycasting.h"
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <limits.h>
// # include "minilibx-linux/mlx.h"

//check_file.c
int	check_filename(char *map_name);
int	count_line(int fd);

//takes_info.c
char	**read_file(int fd, int nbline);
int	get_fd(char *file);

//parsing.c
int start(char **av, t_cub *info);
int info_distrib(char **file, t_cub *info);

//parse_color.c
int give_color(t_color *fc, char *line);
int check_values(char **values);
int check_point(char *line);
int	choose_fc(t_cub *info, char *line);

//parse_texture
int	choose_texture(t_cub *info, char *line);
void	stock_texture(t_texture *tex, char *line);

// tools.c
long	my_atol(const char *nptr);
int	    ft_strcmp(char *s1, char *s2);
void	error_msg(char *msg);
int	is_blank_line(char *line);

//build_map.c
void	file_to_map(char **file, t_cub *info);

//parse_map.c
char	**ft_map_duplicate(t_cub *info);


#endif
