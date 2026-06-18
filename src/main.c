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

// ./cub3d map.cub

int main(int ac, char **av)
{
    t_cub   *info;

    info = malloc(10000);
    if (ac != 2)
        return (printf("Invalid Number of argument"), 1);
    if (start(av, info) != 0)
        return (1);
    free(info);
    //init_struct
    //parsing
    //exec/raycasting
    //free_all
    return (0);
}
