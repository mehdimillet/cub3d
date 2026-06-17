/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by you               #+#    #+#             */
/*   Updated: 2026/06/17 14:28:21 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define FOV (PI / 3.0)

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	angle;
	double	perp_dist;
	double	hit_x;
	double	hit_y;
	int		wall_type;
	int		hit_vertical;
}	t_ray;

typedef struct s_raycaster
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_cub	*map;
	double	player_x;
	double	player_y;
	double	player_angle;
}	t_raycaster;

// raycasting_core.c
double	normalize_angle(double angle);
int		get_wall_type(t_ray *ray);
int		is_wall(t_cub *map, double x, double y);
int		cast_ray(t_raycaster *ray_data, double angle, t_ray *ray);
int		raycasting_loop(t_raycaster *ray_data);

// raycasting.c
int		game_loop(t_raycaster *ray_data);
int		start_raycasting(t_cub *map);

// renderer.c
int		get_color_from_wall(int wall_type);
void	render_column(t_raycaster *ray_data, int col, t_ray *ray);
void	render_frame(t_raycaster *ray_data);

// mlx_engine.c
int		init_mlx(t_raycaster *ray_data);
void	put_pixel(t_raycaster *ray_data, int x, int y, int color);
void	destroy_mlx(t_raycaster *ray_data);

// input.c
int		key_press(int keycode, t_raycaster *ray_data);
int		key_release(int keycode, t_raycaster *ray_data);
int		close_window(t_raycaster *ray_data);

// movement.c
int		is_walkable(t_cub *map, double x, double y);
void	update_player(t_raycaster *ray_data, double delta_time);

#endif
