/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:19:32 by memillet          #+#    #+#             */
/*   Updated: 2026/06/30 13:29:44 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

// #include "../headers/raycasting.h"

// ./cub3d map.cub

int	main(int ac, char **av)
{
	t_cub	info;

	ft_memset(&info, 0, sizeof(t_cub));
	if (ac != 2)
		return (printf("Invalid Number of argument"), 1);
	if (parse_the_world(av, &info) != 0)
		return (1);
	start_raycasting(&info);
	free_cub(&info);
	return (0);
}
