/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:41 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 13:26:08 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_column(t_raycaster *rc, t_ray *ray, t_draw_col *dc)
{
	t_texture	*tex;
	int			wall_height;
	int			tex_x;
	int			y;

	if (ray->tile == 'D')
		tex = &rc->map->tex[4];
	else
		tex = &rc->map->tex[ray->wall_type];
	wall_height = dc->end - dc->start;
	if (wall_height <= 0)
		wall_height = 1;
	tex_x = get_tex_x(ray, tex);
	y = 0;
	while (y < dc->start && y < SCREEN_HEIGHT)
		put_pixel(rc, dc->col, y++, color_to_int(rc->map->ceiling));
	while (y <= dc->end && y < SCREEN_HEIGHT)
	{
		put_pixel(rc, dc->col, y, get_tex_pixel(tex, tex_x,
				((y - dc->start) * tex->length) / wall_height));
		y++;
	}
	while (y < SCREEN_HEIGHT)
		put_pixel(rc, dc->col, y++, color_to_int(rc->map->floor));
}

void	render_column(t_raycaster *ray_data, int col, t_ray *ray)
{
	t_draw_col	dc;
	int			wall_height;
	int			offset;

	offset = get_view_offset(ray_data);
	wall_height = (int)(SCREEN_HEIGHT / ray->perp_dist);
	dc.col = col;
	dc.start = (SCREEN_HEIGHT - wall_height) / 2 + offset;
	dc.end = (SCREEN_HEIGHT + wall_height) / 2 + offset;
	draw_column(ray_data, ray, &dc);
}

void	render_frame(t_raycaster *ray_data)
{
	mlx_put_image_to_window(ray_data->mlx_ptr, ray_data->win_ptr,
		ray_data->img.img, 0, 0);
}
