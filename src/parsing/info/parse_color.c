/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 05:11:16 by memillet          #+#    #+#             */
/*   Updated: 2026/06/25 17:05:43 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	choose_fc(t_cub *info, char *line)
{
	if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
	{
		if (info->seen[F] == 1)
			return (error_msg("Error\nDuplicate F\n"), 1);
		info->seen[F] = 1;
		if (give_color(&info->floor, line) != 0)
			return (1);
	}
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
	{
		if (info->seen[C] == 1)
			return (error_msg("Error\nDuplicate C\n"), 1);
		info->seen[C] = 1;
		if (give_color(&info->ceiling, line) != 0)
			return (1);
	}
	return (0);
}

int	check_point(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[0] == ',' || line[ft_strlen(line) - 1] == ',')
		return (error_msg("Error\nComma at start or end of the string\n"), 1);
	while (line[i])
	{
		if (line[i] == ',')
		{
			if (line[i - 1] == ',')
				return (error_msg("Error\nEmpty element\n"), 1);
			j++;
		}
		i++;
	}
	if (j != 2)
		return (error_msg("Error\nWrong number of element\n"), 1);
	return (0);
}

int	check_values(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (!(ft_isdigit(values[i][j])))
				return (error_msg("Error\nNon-digital character\n"), 1);
			j++;
		}
		if (my_atol(values[i]) > 255)
			return (error_msg("Error\nWrong values\n"), 1);
		i++;
	}
	return (0);
}

//start i at 1 because line[0] = F or C
int	give_color(t_color *fc, char *line)
{
	int		i;
	char	**values;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (check_point(&line[i]) != 0)
		return (1);
	values = ft_split(&line[i], ',');
	if (!values)
		return (1);
	if (check_values(values) != 0)
		return (free_tab(values), 1);
	fc->red = my_atol(values[0]);
	fc->green = my_atol(values[1]);
	fc->blue = my_atol(values[2]);
	free_tab(values);
	return (0);
}
