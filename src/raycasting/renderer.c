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

// couleur temporaire par direction, sera remplace par les textures
int	get_color_from_wall(int wall_type)
{
	if (wall_type == NO)
		return (0x00FF0000);
	if (wall_type == SO)
		return (0x0000FF00);
	if (wall_type == EA)
		return (0x000000FF);
	return (0x00FFFFFF);
}

// convertit une t_color (r,g,b) en entier RGB utilisable par put_pixel
static int	color_to_int(t_color c)
{
	return (c.red << 16 | c.green << 8 | c.blue);
}

// dessine les pixels de la colonne : plafond, mur, sol
static void	draw_column(t_raycaster *rc, int col, t_ray *ray, int start, int end)
{
	int	y;

	y = 0;
	while (y < start)
		put_pixel(rc, col, y++, color_to_int(rc->map->ceiling));
	while (y <= end)
		put_pixel(rc, col, y++, get_color_from_wall(ray->wall_type));
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
