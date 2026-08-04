/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:08 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 14:28:00 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// stores the values of the mlx in the ray_data structure
int	init_mlx(t_raycaster *ray_data)
{
	ray_data->mlx_ptr = mlx_init();
	if (!ray_data->mlx_ptr)
		return (1);
	ray_data->win_ptr = mlx_new_window(ray_data->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3D");
	if (!ray_data->win_ptr)
		return (1);
	ray_data->img.img = mlx_new_image(ray_data->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!ray_data->img.img)
		return (1);
	ray_data->img.addr = mlx_get_data_addr(ray_data->img.img,
			&ray_data->img.bits_per_pixel, &ray_data->img.line_length,
			&ray_data->img.endian);
	if (!ray_data->img.addr)
		return (1);
	if (load_textures(ray_data))
		return (1);
	return (0);
}

// write the color in the buffer address
void	put_pixel(t_raycaster *ray_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = ray_data->img.addr + (y * ray_data->img.line_length + x
			* (ray_data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// destroy the values of the struct that we set in init_mlx
void	destroy_mlx(t_raycaster *ray_data)
{
	free_textures(ray_data, 4 + (ray_data->map && ray_data->map->seen[D] == 1));
	if (ray_data->img.img)
		mlx_destroy_image(ray_data->mlx_ptr, ray_data->img.img);
	if (ray_data->win_ptr)
		mlx_destroy_window(ray_data->mlx_ptr, ray_data->win_ptr);
	if (ray_data->mlx_ptr)
	{
		mlx_destroy_display(ray_data->mlx_ptr);
		free(ray_data->mlx_ptr);
	}
}
