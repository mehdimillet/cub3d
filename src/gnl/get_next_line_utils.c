/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:22:49 by memillet          #+#    #+#             */
/*   Updated: 2026/06/30 13:28:36 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (NULL);
}

static void	*my_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	int				i;

	i = 0;
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while ((size_t)i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = (my_strlen(s1) + my_strlen(s2));
	dest = my_calloc(size + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(dest + j + i) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	free((void *)s1);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)my_strlen(s))
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (len > (unsigned int)my_strlen(s + start))
		len = my_strlen(s + start);
	dest = my_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
