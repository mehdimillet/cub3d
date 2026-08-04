/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:17 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 13:25:19 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
