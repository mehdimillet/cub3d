/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:03:03 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/30 13:29:01 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"

static void	calc_delta(t_dda *dda)
{
	if (dda->dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1.0 / dda->dir_x);
	if (dda->dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1.0 / dda->dir_y);
}

static void	calc_step(t_raycaster *rc, t_dda *dda)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (rc->player_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - rc->player_x)
			* dda->delta_dist_x;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (rc->player_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - rc->player_y)
			* dda->delta_dist_y;
	}
}

static void	dda_loop(t_raycaster *rc, t_dda *dda)
{
	while (1)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (is_wall(rc->map, dda->map_x, dda->map_y))
			break ;
	}
}

int	cast_ray(t_raycaster *rc, double angle, t_ray *ray)
{
	t_dda	dda;

	ray->angle = angle;
	dda.dir_x = cos(angle);
	dda.dir_y = sin(angle);
	dda.map_x = (int)rc->player_x;
	dda.map_y = (int)rc->player_y;
	calc_delta(&dda);
	calc_step(rc, &dda);
	dda_loop(rc, &dda);
	if (dda.side == 0)
		ray->perp_dist = (dda.map_x - rc->player_x
				+ (1 - dda.step_x) / 2.0) / dda.dir_x;
	else
		ray->perp_dist = (dda.map_y - rc->player_y
				+ (1 - dda.step_y) / 2.0) / dda.dir_y;
	ray->hit_x = rc->player_x + ray->perp_dist * dda.dir_x;
	ray->hit_y = rc->player_y + ray->perp_dist * dda.dir_y;
	ray->hit_vertical = (dda.side == 1);
	ray->wall_type = get_wall_type(ray);
	return (0);
}
