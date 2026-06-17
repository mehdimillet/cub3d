/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:08 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/16 14:38:13 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include "../minilibx-linux/mlx.h"

int	init_mlx(t_raycaster *ray_data)
{
	(void)ray_data;
	return (0);
}

void	put_pixel(t_raycaster *ray_data, int x, int y, int color)
{
	(void)ray_data;
	(void)x;
	(void)y;
	(void)color;
}

void	destroy_mlx(t_raycaster *ray_data)
{
	(void)ray_data;
}
