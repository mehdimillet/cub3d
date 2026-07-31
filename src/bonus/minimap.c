/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:44:18 by memillet          #+#    #+#             */
/*   Updated: 2026/07/31 15:51:19 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	put_tile(t_raycaster *rc, int px, int py, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < rc->tile)
	{
		j = 0;
		while (j < rc->tile)
		{
			put_pixel(rc, px + j, py + i, color);
			j++;
		}
		i++;
	}
}

void	put_player(t_raycaster *rc, int px, int py, int color)
{
	int	i;
	int	j;
	int	r;

	r = TILE_PLAYER;
	i = -r;
	while (i <= r)
	{
		j = -r;
		while (j <= r)
		{
			put_pixel(rc, px + j, py + i, color);
			j++;
		}
		i++;
	}
}

static int	tile_calcul(t_raycaster *rc)
{
	int	tile_w;
	int	tile_h;

	tile_w = MINIMAP_MAX / rc->map->width;
	tile_h = MINIMAP_MAX / rc->map->height;
	if (tile_w < tile_h)
		return (tile_w);
	return (tile_h);
}

void	draw_minimap(t_raycaster *rc)
{
	int	y;
	int	x;

	rc->tile = tile_calcul(rc);
	if (rc->tile < 1)
		rc->tile = 1;
	y = 0;
	while (rc->map->map[y])
	{
		x = 0;
		while (rc->map->map[y][x])
		{
			if (rc->map->map[y][x] == '1')
				put_tile(rc, x * rc->tile, y * rc->tile, MINIMAP_WALL);
			else if (ft_strchr("0NSEW", rc->map->map[y][x]))
				put_tile(rc, x * rc->tile, y * rc->tile, MINIMAP_FLOOR);
			x++;
		}
		y++;
	}
	put_player(rc, (int)(rc->player_x * rc->tile),
		(int)(rc->player_y * rc->tile), MINIMAP_PLAYER);
}
