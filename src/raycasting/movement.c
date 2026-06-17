/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:22 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/16 14:38:24 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include <math.h>

# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.05

int	is_walkable(t_cub *map, double x, double y)
{
	(void)map;
	(void)x;
	(void)y;
	return (0);
}

void	update_player(t_raycaster *ray_data, double delta_time)
{
	(void)ray_data;
	(void)delta_time;
}
