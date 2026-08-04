/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:24:07 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 14:26:11 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// activates the key flag 
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
	if (keycode == 101)
		toggle_door(ray_data);
	if (keycode == 65307)
		close_window(ray_data);
	return (0);
}

// deactivates the flag of the released key
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
