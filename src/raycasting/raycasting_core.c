/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:29 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/16 15:52:34 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/includes.h"

// en gros c'est une fonction pour transformer le radian d'un cercle en un radian valide de 0-2pi(2pi = 360 degrees) zeubi
double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

int	get_wall_type(t_raycaster *ray_data, double hit_x, double hit_y,
		double angle)
{
	(void)ray_data;
	(void)hit_x;
	(void)hit_y;
	(void)angle;
	return (0);
}

// fonction pour verif si c'est un mur ou pas(j'ai compte les bords de map comme des murs)
int	is_wall(t_cub *map, double x, double y)
{
	int grid_x;
	int grid_y;
	char c;
	grid_x = (int)floor(x);
	grid_y = (int)floor(y);
	if (grid_x < 0 || grid_y < 0 || grid_y >= map->length || grid_x >= map->width)
		return (1);
	c = map->map[grid_y][grid_x];
	if (c == '1')
		return (1);
	return (0);
}

int	cast_ray(t_raycaster *ray_data, double angle, t_ray *ray)
{
	(void)ray_data;
	(void)angle;
	(void)ray;
	return (0);
}

int	raycasting_loop(t_raycaster *ray_data)
{
	(void)ray_data;
	return (0);
}
