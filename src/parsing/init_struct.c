/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:38:01 by memillet          #+#    #+#             */
/*   Updated: 2026/06/30 13:31:54 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	init_cub(t_cub *info)
{
	info->height = -1;
	info->width = -1;
	info->map_start = -1;
}

void	init_player(t_player *j)
{
	j->column = 0;
	j->line = 0;
	j->player_count = 0;
}
