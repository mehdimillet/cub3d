/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:34 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 13:26:01 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BOB_SPEED 11.0
#define BOB_AMPLITUDE 9.0

static double	get_delta_time(void)
{
	static struct timeval	last = {0, 0};
	struct timeval			now;
	double					dt;

	gettimeofday(&now, NULL);
	if (last.tv_sec == 0)
	{
		last = now;
		return (0.0);
	}
	dt = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) / 1e6;
	last = now;
	if (dt > 0.05)
		dt = 0.05;
	return (dt);
}

static int	is_moving(t_raycaster *ray_data)
{
	return (ray_data->key_w || ray_data->key_s || ray_data->key_a
		|| ray_data->key_d);
}

static void	update_bob(t_raycaster *ray_data, double dt)
{
	ray_data->anim_time += dt;
	if (!is_moving(ray_data))
	{
		ray_data->view_bob = 0;
		return ;
	}
	ray_data->view_bob = (int)(sin(ray_data->anim_time * BOB_SPEED)
			* BOB_AMPLITUDE);
}

int	game_loop(t_raycaster *ray_data)
{
	t_ray	ray;
	double	angle;
	int		col;
	double	dt;

	col = 0;
	dt = get_delta_time();
	update_player(ray_data, dt);
	update_bob(ray_data, dt);
	while (col < SCREEN_WIDTH)
	{
		angle = ray_data->player_angle - (FOV / 2.0) + ((double)col * FOV
				/ SCREEN_WIDTH);
		cast_ray(ray_data, angle, &ray);
		render_column(ray_data, col, &ray);
		col++;
	}
	draw_minimap(ray_data);
	render_frame(ray_data);
	return (0);
}

// mlx_mouse_hide(ray_data.mlx_ptr, ray_data.win_ptr);
// top of mlx_mouse_move 
int	start_raycasting(t_cub *map)
{
	t_raycaster	ray_data;

	ft_memset(&ray_data, 0, sizeof(t_raycaster));
	ray_data.map = map;
	ray_data.player_x = map->pos.column;
	ray_data.player_y = map->pos.line;
	ray_data.player_angle = map->pos.orientation;
	if (init_mlx(&ray_data))
		return (1);
	ray_data.mouse_initialized = 1;
	ray_data.mouse_ignore_next = 0;
	ray_data.last_mouse_x = SCREEN_WIDTH / 2;
	mlx_mouse_move(ray_data.mlx_ptr, ray_data.win_ptr, SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2);
	mlx_hook(ray_data.win_ptr, 2, 1L << 0, key_press, &ray_data);
	mlx_hook(ray_data.win_ptr, 3, 1L << 1, key_release, &ray_data);
	mlx_hook(ray_data.win_ptr, 6, 1L << 6, mouse_move, &ray_data);
	mlx_hook(ray_data.win_ptr, 17, 0, close_window, &ray_data);
	mlx_loop_hook(ray_data.mlx_ptr, game_loop, &ray_data);
	mlx_loop(ray_data.mlx_ptr);
	return (0);
}
