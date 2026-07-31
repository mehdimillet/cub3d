/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:54:05 by memillet          #+#    #+#             */
/*   Updated: 2026/07/31 17:14:20 by memillet         ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

/* ************************* check_file.c ********************** */
int		check_filename(char *map_name);
int		count_line(int fd);

/* ************************* takes_info.c ************************** */
char	**read_file(int fd, int nbline);
int		get_fd(char *file);

/* ************************* parsing.c ************************* */
int		parse_the_world(char **av, t_cub *info);
int		info_distrib(char **file, t_cub *info);

/* ************************* parse_color.c *********************** */
int		give_color(t_color *fc, char *line);
int		check_values(char **values);
int		check_point(char *line);
int		choose_fc(t_cub *info, char *line);

/* ************************ parse_texture.c ************************* */
int		choose_texture(t_cub *info, char *line);
void	stock_texture(t_texture *tex, char *line, int id);

/* ************************* parse_map.c ********************* */
char	**ft_map_duplicate(t_cub *info);
int		check_charset_and_player(t_cub *info);
int		check_map_closed(t_cub *info);

/* ************************ build_map.c ********************************* */
int		file_to_map(char **file, t_cub *info);

/* ************************ init_struct.c ************************ */
void	init_player(t_player *j);

/* ************************ tools.c *************************** */
long	my_atol(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	error_msg(char *msg);
int		is_blank_line(char *line);
void	free_cub(t_cub *info);

/* *********************** minimap.c **************************** */
void	draw_minimap(t_raycaster *rc);
void	put_tile(t_raycaster *rc, int px, int py, int color);

/* ************************ door.c ****************************** */
void	toggle_door(t_raycaster *rc);
int		if_door(t_cub *info);

/* ************************ raycasting_core.c ****************************** */
double	normalize_angle(double angle);
int		get_wall_type(t_ray *ray);
int		is_wall(t_cub *map, double x, double y);
int		raycasting_loop(t_raycaster *ray_data);

/* ************************ cast_ray.c ****************************** */
int		cast_ray(t_raycaster *rc, double angle, t_ray *ray);

/* ************************ raycasting.c ****************************** */
int		game_loop(t_raycaster *ray_data);
int		start_raycasting(t_cub *map);

/* ************************ renderer.c ****************************** */
void	render_column(t_raycaster *ray_data, int col, t_ray *ray);
void	render_frame(t_raycaster *ray_data);
int		get_view_offset(t_raycaster *ray_data);

/* ************************ mlx_engine.c ****************************** */
int		init_mlx(t_raycaster *ray_data);
void	put_pixel(t_raycaster *ray_data, int x, int y, int color);
void	destroy_mlx(t_raycaster *ray_data);

/* ************************ input.c ****************************** */
int		key_press(int keycode, t_raycaster *ray_data);
int		key_release(int keycode, t_raycaster *ray_data);
int		mouse_move(int x, int y, t_raycaster *ray_data);
int		close_window(t_raycaster *ray_data);

/* ************************ movement.c ****************************** */
int		is_walkable(t_cub *map, double x, double y);
void	update_player(t_raycaster *ray_data, double delta_time);

#endif