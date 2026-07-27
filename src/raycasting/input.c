/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:17 by leauvray          #+#    #+#             */
/*   Updated: 2026/07/27 17:46:36 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"

static void	center_mouse(t_raycaster *ray_data)
{
	mlx_mouse_move(ray_data->mlx_ptr, ray_data->win_ptr, SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2);
}

static int	ignore_initial_mouse(t_raycaster *ray_data)
{
	ray_data->mouse_initialized = 1;
	ray_data->last_mouse_x = SCREEN_WIDTH / 2;
	ray_data->mouse_ignore_next = 1;
	center_mouse(ray_data);
	return (0);
}

static int	apply_mouse_motion(int x, t_raycaster *ray_data)
{
	int	delta_x;

	delta_x = x - SCREEN_WIDTH / 2;
	if (delta_x != 0)
	{
		ray_data->player_angle += delta_x * MOUSE_SENSITIVITY;
		ray_data->player_angle = normalize_angle(ray_data->player_angle);
	}
	ray_data->last_mouse_x = SCREEN_WIDTH / 2;
	ray_data->mouse_ignore_next = 1;
	center_mouse(ray_data);
	return (0);
}

int	mouse_move(int x, int y, t_raycaster *ray_data)
{
	(void)y;
	if (ray_data->mouse_ignore_next)
	{
		ray_data->mouse_ignore_next = 0;
		return (0);
	}
	if (!ray_data->mouse_initialized)
		return (ignore_initial_mouse(ray_data));
	return (apply_mouse_motion(x, ray_data));
}

// active le flag de la touche pressee
int	key_press(int keycode, t_raycaster *ray_data)

{
	if (keycode == 119)
		ray_data->key_w = 1;
	if (keycode == 115)
		ray_data->key_s = 1;
	if (keycode == 97)
		ray_data->key_a = 1;
	if (keycode == 100)
		ray_data->key_d = 1;
	if (keycode == 65361)
		ray_data->key_left = 1;
	if (keycode == 65363)
		ray_data->key_right = 1;
	if (keycode == 65307)
		close_window(ray_data);
	return (0);
}

// desactive le flag de la touche relachee
int	key_release(int keycode, t_raycaster *ray_data)

{
	if (keycode == 119)
		ray_data->key_w = 0;
	if (keycode == 115)
		ray_data->key_s = 0;
	if (keycode == 97)
		ray_data->key_a = 0;
	if (keycode == 100)
		ray_data->key_d = 0;
	if (keycode == 65361)
		ray_data->key_left = 0;
	if (keycode == 65363)
		ray_data->key_right = 0;
	return (0);
}

int	close_window(t_raycaster *ray_data)
{
	destroy_mlx(ray_data);
	free_cub(ray_data->map);
	exit(0);
}
