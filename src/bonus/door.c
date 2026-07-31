/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:08:32 by memillet          #+#    #+#             */
/*   Updated: 2026/07/31 16:41:33 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	toggle_door(t_raycaster *rc)
{
	double	tx;
	double	ty;
	int		len;

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

int	if_door(t_cub *info)
{
	if (info->door_found == 1 && info->seen[D] == 0)
		return (error_msg("Error\nDoors in map but not the texture\n"), 1);
	if (info->door_found == 0 && info->seen[D] == 1)
		return (error_msg("Error\nNo doors in the map but have texture\n"), 1);
	return (0);
}
