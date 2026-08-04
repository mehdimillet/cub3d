/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:19:32 by memillet          #+#    #+#             */
/*   Updated: 2026/08/04 15:25:42 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	info;

	ft_memset(&info, 0, sizeof(t_cub));
	if (ac != 2)
		return (printf("Invalid Number of argument"), 1);
	if (parse_the_world(av, &info) != 0)
		return (1);
	if (start_raycasting(&info) != 0)
    	return (free_cub(&info), 1);
	free_cub(&info);
	return (0);
}
