/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:35:45 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/24 13:05:12 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_bool	get_sizemap(int fd, t_map *map)
{
	char	buff;
	int		height;
	int		width;
	int		save_width;

	save_width = -1;
	height = 0;
	width = 0;
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
		{
			if (width != save_width && save_width != -1)
				return (faux);
			height++;
			save_width = width;
			width = -1;
		}
		else if (!valid_char_param(buff))
			return (faux);
		width++;
	}
	map->width = save_width;
	map->height = height + 1;
	return (width == save_width);
}

int	set_map(t_map *map)
{
	char	c;
	int		fd;
	int		i;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = -1;
	while (++i < map->height)
	{
		if (read(fd, map->map[i], map->width) < 0)
			return (0);
		map->map[i][map->width] = '\0';
		if (read(fd, &c, 1) < 0 || c != '\n')
			return (0);
	}
	return (1);
}

int	parse_map(t_map *map)
{
	int	fd;
	int	i;

	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (get_sizemap(fd, map) == faux)
		return (0);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	i = -1;
	while (++i < map->height)
		map->map[i] = malloc(map->width + 1);
	map->map[i] = 0;
	return (set_map(map));
}
