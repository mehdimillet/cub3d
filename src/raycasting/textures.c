/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:27:12 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 14:52:41 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_raycaster *ray_data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ray_data->map->tex[i].img)
			mlx_destroy_image(ray_data->mlx_ptr, ray_data->map->tex[i].img);
		i++;
	}
}

static int	load_one_texture(t_raycaster *ray_data, int i)
{
	if (!ray_data->map->tex[i].path)
		return (error_msg("Error\nMissing texture path\n"),
			free_textures(ray_data, i), 1);
	ray_data->map->tex[i].img = mlx_xpm_file_to_image(ray_data->mlx_ptr,
			ray_data->map->tex[i].path, &ray_data->map->tex[i].width,
			&ray_data->map->tex[i].length);
	if (!ray_data->map->tex[i].img)
		return (error_msg("Error\nFailed to load texture\n"),
			free_textures(ray_data, i), 1);
	ray_data->map->tex[i].addr = mlx_get_data_addr(
			ray_data->map->tex[i].img,
			&ray_data->map->tex[i].bits_per_pixel,
			&ray_data->map->tex[i].line_length,
			&ray_data->map->tex[i].endian);
	if (!ray_data->map->tex[i].addr)
		return (error_msg("Error\nFailed to get texture addr\n"),
			free_textures(ray_data, i + 1), 1);
	return (0);
}

int	load_textures(t_raycaster *ray_data)
{
	int	i;
	int	max;

	i = 0;
	max = 4;
	if (ray_data->map->seen[D] == 1)
		max = 5;
	while (i < max)
	{
		if (load_one_texture(ray_data, i))
			return (1);
		i++;
	}
	return (0);
}
