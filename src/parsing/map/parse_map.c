/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:26:30 by memillet          #+#    #+#             */
/*   Updated: 2026/06/25 17:03:23 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

static double	char_to_angle(char c)
{
	if (c == 'N')
		return (3.0 * PI / 2.0);
	if (c == 'S')
		return (PI / 2.0);
	if (c == 'E')
		return (0.0);
	return (PI);
}

void	is_player(t_cub *info, int x, int y)
{
	info->pos.player_count++;
	info->pos.line = y + 0.5;
	info->pos.column = x + 0.5;
	info->pos.orientation = char_to_angle(info->map[y][x]);
}

int	check_charset_and_player(t_cub *info)
{
	int			y;
	int			x;
	const char	*allowed;

	allowed = "01NSEW ";
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (!ft_strchr(allowed, info->map[y][x]))
				return (error_msg("Error\nInvalid char in map\n"), 1);
			if (ft_strchr("NSEW", info->map[y][x]))
				is_player(info, x, y);
			x++;
		}
		y++;
	}
	if (info->pos.player_count != 1)
		return (error_msg("Error\nMust have exactly one player\n"), 1);
	return (0);
}

void	flood_fill(char	**map_cpy, int y, int x, t_cub *info)
{
	if (y < 0 || y >= info->height || x < 0
		|| x >= (int)ft_strlen(map_cpy[y])
		|| map_cpy[y][x] == '\0' || map_cpy[y][x] == ' ')
	{
		info->leak = 1;
		return ;
	}
	if (map_cpy[y][x] == 'V' || map_cpy[y][x] == '1')
		return ;
	else
		map_cpy[y][x] = 'V';
	flood_fill(map_cpy, y, x + 1, info);
	flood_fill(map_cpy, y, x - 1, info);
	flood_fill(map_cpy, y + 1, x, info);
	flood_fill(map_cpy, y - 1, x, info);
}

int	check_map_closed(t_cub *info)
{
	char	**copy;

	copy = ft_map_duplicate(info);
	if (!copy)
		return (1);
	info->leak = 0;
	flood_fill(copy, (int)info->pos.line, (int)info->pos.column, info);
	free_tab(copy);
	if (info->leak)
		return (error_msg("Error\nMap is not closed\n"), 1);
	return (0);
}
