/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:00:10 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/20 13:24:31 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_bool	valid_extension(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		return (faux);
	return (ft_strcmp(filename + (i - 4), ".ber") == 0);
}

t_bool	valid_char_param(const char c)
{
	return (c == START || c == EXIT || c == WALL || c == BLANK || c == ITEM);
}

int	get_sizemap(int fd, t_map *map) 
{
	char	buff;
	int		height;
	int		width;
	int		save_width;

	save_width = -1;
	height = 0;
	width = 0;
	while (read(fd, & buff, 1))
	{
		if (buff == '\n')
		{
			if (width != save_width && save_width != -1)
				return (-1);
			height++;
			save_width = width;
			width = 0;
		}
		else if (!valid_char_param(buff))
			return (-1);
		else
			width++;
	}
	map->width = save_width;
	map->height = height + 1;
	return (1);
}

int	set_map(t_map *map)
{
	char	c;
	int		fd;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	for (int i = 0; i < map->height; i++)
	{
		if (read(fd, map->map[i], map->width) < 0)
			return (-1);
		map->map[i][map->width] = '\0';
		// skip \n
		if (read(fd, & c, 1) < 0 || c != '\n')
			return (-1);
	}
	return (0);
}

int	parse_map(t_map *map)
{
	int	fd;

	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_sizemap(fd, map) < 0)
		return (-1);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	int i = 0;
	for (; i < map->height; i++)
		map->map[i] = malloc(map->width + 1);
	map->map[i] = 0;
	return (set_map(map));
}

void	virus_col(t_map *map, int y, int x, int add)
{
	while (y >= 0 && y < map->height - 1 && map->map[y][x] != WALL)
	{
		if (!map->test)
			map->test = map->map[y][x] != '*';
		map->map[y][x] = '*';
		y += add;
	}
}

void	virus_row(t_map *map, int y, int x, int add)
{
	while (x >= 0 && x < map->width - 1 && map->map[y][x] != WALL)
	{
		if (!map->test)
			map->test = map->map[y][x] != '*';
		map->map[y][x] = '*';
		x += add;
	}
}

void	virus(int y, int x, t_map *map)
{
	virus_col(map, y, x, 1);
	virus_col(map, y, x, -1);
	virus_row(map, y, x, -1);
	virus_row(map, y, x, 1);
}

int	find_valid_path(t_map *map)
{
	// send p position first
	virus(map->start_y, map->start_x, map);
	map->test = 0;
	// others later
	for (int i = 1; i < map->height - 1; i++) {
		for (int j = 1; j < map->width - 1; j++) {
			if (map->map[i][j] == '*') {
				virus(i, j, map);
			}
		}
	}
	return 0;
}
