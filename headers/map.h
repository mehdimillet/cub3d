/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:54:18 by memillet          #+#    #+#             */
/*   Updated: 2026/07/28 17:04:29 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

// color for the celling and the floor
# ifndef TILE
#  define TILE 10
# endif

# ifndef MINIMAP_FLOOR
#  define MINIMAP_FLOOR 0xAAAAAA
# endif

# ifndef MINIMAP_WALL
#  define MINIMAP_WALL 0x444444
# endif

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_texture
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			length;
	int			width;
}				t_texture;

// struct wich contains the infos of map
// tex[0] NO / tex[1] SO / tex[2] WE/ tex[3] EA
typedef struct s_cub
{
	char		**map;
	int			leak;
	int			nb_line;
	int			height;
	int			width;
	int			map_start;
	int			seen[6];
	t_color		floor;
	t_color		ceiling;
	t_player	pos;
	t_texture	tex[4];
}			t_cub;

#endif