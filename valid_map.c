/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:15:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/22 19:56:00 by jewancti         ###   ########.fr       */
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

static void	set_position(const int pos[2], int index, t_map *map)
{
	if (pos[0] == 1 && map->start_y == -1 && map->start_x == -1)
	{
		map->start_y = index / map->width;
		map->start_x = index % map->width;
	}
	if (pos[1] == 1 && map->exit_y == -1 && map->exit_x == -1)
	{
		map->exit_y = index / map->width;
		map->exit_x = index % map->width;
	}
}

static t_bool	valid_startexitposition(t_map *tmap)
{
	char		**map;
	char		c;
	int	founds[4] = {0, 0, 0, 0};
	int			i;

	i = 0;
	map = tmap->map;
	while (i < (tmap->height * tmap->width))
	{
		c = map[i / tmap->width][i % tmap->width];
		if (c == START || c == EXIT || c == BLANK || c == ITEM)
		{
			founds[0] += c == START;
			founds[1] += c == EXIT;
			founds[2] += c == BLANK;
			founds[3] += c == ITEM;
			if (founds[0] > 1 || founds[1] > 1)
				return (faux);
			set_position((const int [2]) {founds[0], founds[1]}, i, tmap);
		}
		i++;
	}
	return (founds[0] > 0 && founds[1] > 0 && founds[2] > 0 && founds[3] > 0);
}

t_bool	valid_map(t_map *map)
{
	return (valid_wall((*map).map[0]) && valid_wall((*map).map[(*map).height - 1]) &&
		side_check(*map, 0, 0) && side_check(*map, 0, (*map).width - 1) && valid_startexitposition(map));
}
