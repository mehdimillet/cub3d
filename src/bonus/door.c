/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:08:32 by memillet          #+#    #+#             */
/*   Updated: 2026/07/30 18:16:03 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	toggle_door(t_raycaster *rc)
{
	double	tx;
	double	ty;
	int	len;

	tx = rc->player_x + cos(rc->player_angle);
	ty = rc->player_y + sin(rc->player_angle);
	if (tx < 0 || ty < 0 || ty >= rc->map->height)
		return ;
	len = (int)ft_strlen(rc->map->map[(int)ty]);
	if (tx >= len)
		return ;
	if (rc->map->map[(int)ty][(int)tx] == 'D')
		rc->map->map[(int)ty][(int)tx] = 'O';
	else if (rc->map->map[(int)ty][(int)tx] == 'O')
		rc->map->map[(int)ty][(int)tx] = 'D';
}