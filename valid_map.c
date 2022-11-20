/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:15:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/20 12:13:38 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static t_bool	valid_wall(char *firstline)
{
	while (*firstline && *firstline == WALL)
		firstline++;
	return (!*firstline);
}

static t_bool	side_check(t_map map, int y, int x)
{
	while (y < map.height)
	{
		if (map.map[y][x] != WALL)
			return (faux);
		y++;
	}
	return (vrai);
}

static t_bool	valid_startposition(t_map *tmap)
{
	char	**map;
	int	found;
	int	i;

	i = 0;
	found = 0;
	map = tmap->map;
	while (i < (tmap->height * tmap->width))
	{
		if (map[i / tmap->width][i % tmap->width] == START)
		{
			found++;
			if (found > 1)
				return (faux);
			tmap->y = i / tmap->width;
			tmap->x = i % tmap->width;
		}
		i++;
	}
	return (tmap->y > -1 && tmap->x > -1);
}

t_bool	valid_map(t_map *map)
{
	// check first line
	return (valid_wall((*map).map[0]) && valid_wall((*map).map[(*map).height - 1]) &&
		side_check(*map, 0, 0) && side_check(*map, 0, (*map).width - 1) && valid_startposition(map));
		
	// check coter gauche | droit
	// check last line

	
}
