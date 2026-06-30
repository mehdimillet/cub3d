/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:54:05 by memillet          #+#    #+#             */
/*   Updated: 2026/06/30 13:28:16 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include "enum.h"
# include "get_next_line.h"
# include "player.h"
# include "map.h"
# include "raycasting.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
// # include "minilibx-linux/mlx.h"

// check_file.c
int		check_filename(char *map_name);
int		count_line(int fd);

// takes_info.c
char	**read_file(int fd, int nbline);
int		get_fd(char *file);

// parsing.c
int		parse_the_world(char **av, t_cub *info);
int		info_distrib(char **file, t_cub *info);

// parse_color.c
int		give_color(t_color *fc, char *line);
int		check_values(char **values);
int		check_point(char *line);
int		choose_fc(t_cub *info, char *line);

// parse_texture
int		choose_texture(t_cub *info, char *line);
void	stock_texture(t_texture *tex, char *line);

// tools.c
long	my_atol(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	error_msg(char *msg);
int		is_blank_line(char *line);
void	free_cub(t_cub *info);

// build_map.c
void	file_to_map(char **file, t_cub *info);

// parse_map.c
char	**ft_map_duplicate(t_cub *info);
int		check_charset_and_player(t_cub *info);
int		check_map_closed(t_cub *info);

// init_struct.c
void	init_player(t_player *j);

#endif
