/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:19:32 by memillet          #+#    #+#             */
/*   Updated: 2026/06/18 12:07:21 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/raycasting.h"

// ./cub3d map.cub

int main(int ac, char **av)
{
    t_cub   info;

    ft_memset(&info, 0, sizeof(t_cub));
    if (ac != 2)
        return (printf("Invalid Number of argument"), 1);
    if (start(av, &info) != 0)
        return (1);
    return (start_raycasting(&info));
}
