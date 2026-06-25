/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:27:10 by memillet          #+#    #+#             */
/*   Updated: 2026/06/25 16:10:51 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	file_to_map(char **file, t_cub *info)
{
	int	i;
	int	j;

	i = info->map_start;
	j = 0;
	info->map = malloc(sizeof(char *) * (info->nb_line - i + 1));
	if (!info->map)
		return ;
	while (file[i])
	{
		info->map[j] = ft_strdup(file[i]);
		if (!info->map[j])
			return (free_tab(info->map));
		i++;
		j++;
	}
	info->map[j] = NULL;
	info->height = j;
	j = 0;
	while (info->map[j])
	{
		if ((int)ft_strlen(info->map[j]) > info->width)
			info->width = ft_strlen(info->map[j]);
		j++;
	}
}

char	**ft_map_duplicate(t_cub *info)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (info->nb_line - info->map_start + 1));
	if (!new)
		return (NULL);
	while (info->map[i])
	{
		new[i] = ft_strdup(info->map[i]);
		if (!new[i])
			return (free_tab(new), NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}
