/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:08 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/17 15:59:33 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include "../minilibx-linux/mlx.h"

static int	load_textures(t_raycaster *ray_data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ray_data->map->tex[i].img = mlx_xpm_file_to_image(
				ray_data->mlx_ptr,
				ray_data->map->tex[i].path,
				&ray_data->map->tex[i].width,
				&ray_data->map->tex[i].length);
		if (!ray_data->map->tex[i].img)
			return (1);
		ray_data->map->tex[i].addr = mlx_get_data_addr(
				ray_data->map->tex[i].img,
				&ray_data->map->tex[i].bits_per_pixel,
				&ray_data->map->tex[i].line_length,
				&ray_data->map->tex[i].endian);
		if (!ray_data->map->tex[i].addr)
			return (1);
		i++;
	}
	return (0);
}

//stock les valeurs de la mlx dans la structure ray_data
int	init_mlx(t_raycaster *ray_data)
{
	ray_data->mlx_ptr = mlx_init();
	if (!ray_data->mlx_ptr)
		return (1);
	ray_data->win_ptr = mlx_new_window(
			ray_data->mlx_ptr,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"cub3D");
	if (!ray_data->win_ptr)
		return (1);
	ray_data->img.img = mlx_new_image(
			ray_data->mlx_ptr,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!ray_data->img.img)
		return (1);
	ray_data->img.addr = mlx_get_data_addr(
			ray_data->img.img,
			&ray_data->img.bits_per_pixel,
			&ray_data->img.line_length,
			&ray_data->img.endian);
	if (!ray_data->img.addr)
		return (1);
	if (load_textures(ray_data))
		return (1);
	return (0);
}

//ecrire le color dans l'adresse du buffer
void	put_pixel(t_raycaster *ray_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH
		|| y < 0 || y >= SCREEN_HEIGHT)
		return ;

	dst = ray_data->img.addr + (y * ray_data->img.line_length
			+ x * (ray_data->img.bits_per_pixel / 8));

	*(unsigned int *)dst = color;
}

//detruire les valeurs de la struct qu'on a set dans init_mlx
void	destroy_mlx(t_raycaster *ray_data)
{
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
