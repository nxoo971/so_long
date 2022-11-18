/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:15:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/18 22:00:07 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static t_bool	valid_wall(char *firstline)
{
	while (*firstline && *firstline == '1')
		firstline++;
	return (!*firstline);
}

static t_bool	side_check(char **map, int y, int x)
{
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (faux);
		y++;
	}
	return (vrai);
}

t_bool	valid_map(const t_map map)
{
	// check first line
	return (valid_wall(map.map[0]) && valid_wall(map.map[map.height - 1]) &&
		side_check(map.map, 0, 0) && side_check(map.map, 0, map.width));
		
	// check coter gauche | droit
	// check last line

	
}
