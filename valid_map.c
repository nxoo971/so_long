/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:15:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/19 04:13:17 by nxoo             ###   ########.fr       */
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
	const char	**map;
	int	found;
	int	i;
	int	j;

	i = 0;
	found = 0;
	map = tmap->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == START)
			{
				if (found > 0)
					return (faux);
				tmap->y = i;
				tmap->x = j;
				found++;
			}
			j++;
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
