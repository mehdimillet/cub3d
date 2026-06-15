/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:54:15 by memillet          #+#    #+#             */
/*   Updated: 2026/06/15 13:41:29 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/cub3d.h"

int	check_filename(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strcmp(&map_name[len - 4], ".cub") != 0)
		return (printf("wrong file extension\n"), 1);
	return (0);
}