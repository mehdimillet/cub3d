/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:29 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/18 14:58:54 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/includes.h"

// fonction pour transformer angle en radian valide de 0-2pi(2pi = 360 degrees)
double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

//regarde dans quelle direction le rayon allait, N, S, W, E.
int get_wall_type(t_ray *ray)
{
	double	dir_x;
	double	dir_y;
	
	dir_x = cos(ray->angle);
	dir_y = sin(ray->angle);
	
	if (ray->hit_vertical == 0)
	{
		if (dir_x > 0)
		return (EA);
		return (WE);
	}
	if (dir_y > 0)
	return (SO);
	return (NO);
}

// fonction pour verif si c'est un mur ou pas(j'ai compte les bords de map comme des murs)
int	is_wall(t_cub *map, double x, double y)
{
	int grid_x;
	int grid_y;
	char c;
	grid_x = (int)floor(x);
	grid_y = (int)floor(y);
	if (grid_x < 0 || grid_y < 0 || grid_y >= map->height || grid_x >= map->width)
	return (1);
	c = map->map[grid_y][grid_x];
	if (c == '1')
	return (1);
	return (0);
}


int	raycasting_loop(t_raycaster *ray_data)
{
	(void)ray_data;
	return (0);
}
