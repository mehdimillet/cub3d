/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:22 by leauvray          #+#    #+#             */
/*   Updated: 2026/08/04 13:25:38 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MOVE_SPEED 3.0
#define ROTATE_SPEED 2.0

// retourne 1 si la case est accessible (pas un mur, pas hors map)
int	is_walkable(t_cub *map, double x, double y)
{
	int	gx;
	int	gy;
	int	len;

	gx = (int)floor(x);
	gy = (int)floor(y);
	if (gx < 0 || gy < 0 || gy >= map->height)
		return (0);
	len = (int)ft_strlen(map->map[(int)gy]);
	if (gx >= len)
		return (0);
	if (map->map[(int)(y + HITBOX)][(int)(x + HITBOX)] == '1' ||
		map->map[(int)(y + HITBOX)][(int)(x - HITBOX)] == '1' ||
		map->map[(int)(y - HITBOX)][(int)(x + HITBOX)] == '1' ||
		map->map[(int)(y - HITBOX)][(int)(x - HITBOX)] == '1')
		return (0);
	if (ft_strchr("0NSEWO", map->map[gy][gx]))
		return (1);
	return (0);
}

// deplace le joueur selon les touches WASD, bloque si mur
static void	move_player(t_raycaster *rc, double dx, double dy)
{
	if (rc->key_w && is_walkable(rc->map, rc->player_x + dx, rc->player_y + dy))
	{
		rc->player_x += dx;
		rc->player_y += dy;
	}
	if (rc->key_s && is_walkable(rc->map, rc->player_x - dx, rc->player_y - dy))
	{
		rc->player_x -= dx;
		rc->player_y -= dy;
	}
	if (rc->key_a && is_walkable(rc->map, rc->player_x + dy, rc->player_y - dx))
	{
		rc->player_x += dy;
		rc->player_y -= dx;
	}
	if (rc->key_d && is_walkable(rc->map, rc->player_x - dy, rc->player_y + dx))
	{
		rc->player_x -= dy;
		rc->player_y += dx;
	}
}

// applique deplacement et rotation selon les flags clavier
void	update_player(t_raycaster *rc, double dt)
{
	double	speed;

	speed = MOVE_SPEED * dt;
	move_player(rc, cos(rc->player_angle) * speed, sin(rc->player_angle)
		* speed);
	if (rc->key_left)
		rc->player_angle -= ROTATE_SPEED * dt;
	if (rc->key_right)
		rc->player_angle += ROTATE_SPEED * dt;
	rc->player_angle = normalize_angle(rc->player_angle);
}
