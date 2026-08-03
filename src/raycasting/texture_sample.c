/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sample.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:19:51 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/03 15:29:52 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"

int	color_to_int(t_color c)
{
	return (c.red << 16 | c.green << 8 | c.blue);
}

int	get_tex_pixel(t_texture *tex, int tx, int ty)
{
	char	*dst;

	tx = tx % tex->width;
	ty = ty % tex->length;
	dst = tex->addr + (ty * tex->line_length + tx * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	get_tex_x(t_ray *ray, t_texture *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->hit_vertical)
		wall_x = ray->hit_x - floor(ray->hit_x);
	else
		wall_x = ray->hit_y - floor(ray->hit_y);
	tex_x = (int)(wall_x * tex->width);
	if (ray->hit_vertical && (int)floor(ray->hit_x) % 2 == 0)
		tex_x = tex->width - 1 - tex_x;
	else if (!ray->hit_vertical && (int)floor(ray->hit_y) % 2 == 0)
		tex_x = tex->width - 1 - tex_x;
	return (tex_x);
}

int	get_view_offset(t_raycaster *ray_data)
{
	return (ray_data->view_bob);
}
