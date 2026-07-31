/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 21:27:27 by memillet          #+#    #+#             */
/*   Updated: 2026/07/31 16:11:14 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	if_door(t_cub *info)
{
	if (info->door_found == 1 && info->seen[D] == 0)
		return (error_msg("Error\nDoors in map but not the texture\n"), 1);
	if (info->door_found == 0 && info->seen[D] == 1)
		return (error_msg("Error\nNo doors in the map but have texture\n"), 1);
	return (0);
}
