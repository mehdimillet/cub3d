/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:38:34 by leauvray          #+#    #+#             */
/*   Updated: 2026/06/17 15:59:35 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"
#include "../minilibx-linux/mlx.h"

int	game_loop(t_raycaster *ray_data)
{
	(void)ray_data;
	return (0);
}

// initialise raycaster, hooks mlx (clavier et fermeture de fenetre) et lance la boucle de jeu 
int	start_raycasting(t_cub *map)
{
	t_raycaster	ray_data;

	ft_memset(&ray_data, 0, sizeof(t_raycaster));
	ray_data.map = map;

	ray_data.player_x = map->pos.column;
	ray_data.player_y = map->pos.line;
	ray_data.player_angle = map->pos.orientation;

	if (init_mlx(&ray_data))
		return (1);

	mlx_hook(ray_data.win_ptr, 2, 1L << 0, key_press, &ray_data);
	mlx_hook(ray_data.win_ptr, 3, 1L << 1, key_release, &ray_data);
	mlx_hook(ray_data.win_ptr, 17, 0, close_window, &ray_data);

	mlx_loop_hook(ray_data.mlx_ptr, game_loop, &ray_data);
	mlx_loop(ray_data.mlx_ptr);

	return (0);
}
