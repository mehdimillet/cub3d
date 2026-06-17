/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by you               #+#    #+#             */
/*   Updated: 2026/06/17 14:28:21 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
 
typedef struct s_ray
{
	double	angle;
	double	perp_dist;
	double	hit_x;
	double	hit_y;
	int		wall_type;
	int		hit_vertical;
}t_ray;
 
typedef struct s_raycaster
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_cub	*map;
	double	player_x;
	double	player_y;
	double	player_angle;
}t_raycaster;

#endif
