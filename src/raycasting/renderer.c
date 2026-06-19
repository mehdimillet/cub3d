/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:41 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/18 16:37:43 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include "../minilibx-linux/mlx.h"

// convertit une t_color (r,g,b) en entier RGB utilisable par put_pixel
static int	color_to_int(t_color c)
{
	return (c.red << 16 | c.green << 8 | c.blue);
}

// lit un pixel dans une texture a la position (tx, ty)
static int	get_tex_pixel(t_texture *tex, int tx, int ty)
{
	char	*dst;

	tx = tx % tex->width;
	ty = ty % tex->length;
	dst = tex->addr + (ty * tex->line_length + tx * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

// dessine les pixels de la colonne : plafond, mur texturé, sol
static void	draw_column(t_raycaster *rc, int col, t_ray *ray, int start, int end)
{
	t_texture	*tex;
	int			wall_height;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	int			y;

	tex = &rc->map->tex[ray->wall_type];
	wall_height = end - start;
	if (wall_height <= 0)
		wall_height = 1;
	if (ray->hit_vertical)
		wall_x = ray->hit_x - floor(ray->hit_x);
	else
		wall_x = ray->hit_y - floor(ray->hit_y);
	tex_x = (int)(wall_x * tex->width);
	if (ray->hit_vertical && (int)floor(ray->hit_x) % 2 == 0)
		tex_x = tex->width - 1 - tex_x;
	else if (!ray->hit_vertical && (int)floor(ray->hit_y) % 2 == 0)
		tex_x = tex->width - 1 - tex_x;
	y = 0;
	while (y < start)
		put_pixel(rc, col, y++, color_to_int(rc->map->ceiling));
	while (y <= end)
	{
		tex_y = ((y - start) * tex->length) / wall_height;
		put_pixel(rc, col, y++, get_tex_pixel(tex, tex_x, tex_y));
	}
	while (y < SCREEN_HEIGHT)
		put_pixel(rc, col, y++, color_to_int(rc->map->floor));
}

// calcule les bornes du mur et delegue le dessin a draw_column
void	render_column(t_raycaster *ray_data, int col, t_ray *ray)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;

	wall_height = (int)(SCREEN_HEIGHT / ray->perp_dist);
	wall_start = (SCREEN_HEIGHT - wall_height) / 2;
	wall_end = (SCREEN_HEIGHT + wall_height) / 2;
	if (wall_start < 0)
		wall_start = 0;
	if (wall_end >= SCREEN_HEIGHT)
		wall_end = SCREEN_HEIGHT - 1;
	draw_column(ray_data, col, ray, wall_start, wall_end);
}

// affiche le buffer image dans la fenetre
void	render_frame(t_raycaster *ray_data)
{
	mlx_put_image_to_window(ray_data->mlx_ptr,
		ray_data->win_ptr,
		ray_data->img.img, 0, 0);
}
