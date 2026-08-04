/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by you               #+#    #+#             */
/*   Updated: 2026/08/04 14:36:49 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>

# ifndef PI
#  define PI 3.1415926535897932384626
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define FOV 1.0471975511965976
# define MOUSE_SENSITIVITY 0.001

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_ray
{
	double	angle;
	double	perp_dist;
	double	hit_x;
	double	hit_y;
	char	tile;
	int		wall_type;
	int		hit_vertical;
}			t_ray;

typedef struct s_draw_col
{
	int	col;
	int	start;
	int	end;
}	t_draw_col;

typedef struct s_raycaster
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_cub	*map;
	double	player_x;
	double	player_y;
	double	player_angle;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_left;
	int		key_right;
	int		key_e;
	int		mouse_initialized;
	int		last_mouse_x;
	int		mouse_ignore_next;
	double	anim_time;
	int		view_bob;
	int		tile;
}			t_raycaster;

typedef struct s_dda
{
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
}			t_dda;

#endif
