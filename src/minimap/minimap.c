/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:44:18 by memillet          #+#    #+#             */
/*   Updated: 2026/07/28 17:04:39 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	put_tile(t_raycaster *rc, int px, int py, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
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

	r = 2;
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

void	draw_minimap(t_raycaster *rc)
{
	int	y;
	int	x;

	y = 0;
	while (rc->map->map[y])
	{
		x = 0;
		while (rc->map->map[y][x])
		{
			if (rc->map->map[y][x] == '1')
				put_tile(rc, x * TILE, y * TILE, MINIMAP_WALL);
			else if (ft_strchr("0NSEW", rc->map->map[y][x]))
				put_tile(rc, x * TILE, y * TILE, MINIMAP_FLOOR);
			x++;
		}
		y++;
	}
	put_player(rc, (int)(rc->player_x * TILE), (int)(rc->player_y * TILE), MINIMAP_PLAYER);
}
