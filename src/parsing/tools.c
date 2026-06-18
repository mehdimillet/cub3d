/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:49:25 by memillet          #+#    #+#             */
/*   Updated: 2026/06/18 08:27:49 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long	my_atol(const char *nptr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (nptr[i] == 9 || nptr[i] == 10 || nptr[i] == 11
		|| nptr[i] == 12 || nptr[i] == 13 || nptr[i] == 32)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
        if (i > 3)
            return (-1);
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result);
}

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ' ' || line[i] == '\n')
			i++;
		else
			break;
	}
	if (line[i] == '\0')
		return (1);
	return (0);
}