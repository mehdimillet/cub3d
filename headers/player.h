/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:54:29 by memillet          #+#    #+#             */
/*   Updated: 2026/07/27 13:26:54 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# ifndef HITBOX
#  define HITBOX 0.1
# endif

typedef struct s_player
{
	double	line;
	double	column;
	double	orientation;
	int		player_count;
}			t_player;

#endif