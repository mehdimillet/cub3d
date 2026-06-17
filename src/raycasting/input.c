/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:17 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/17 15:59:36 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include "../minilibx-linux/mlx.h"

int	key_press(int keycode, t_raycaster *ray_data)
{
	(void)keycode;
	(void)ray_data;
	return (0);
}

int	key_release(int keycode, t_raycaster *ray_data)
{
	(void)keycode;
	(void)ray_data;
	return (0);
}

int	close_window(t_raycaster *ray_data)
{
	destroy_mlx(ray_data);
	exit(0);
}
