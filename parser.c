/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:00:10 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/18 22:14:12 by jewancti         ###   ########.fr       */
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

int	get_sizemap(int fd, t_map *map) 
{
	char	buff[1];
	int		height;
	int		width;
	int		save_width;

	save_width = 0;
	while (read(fd, buff, 1))
	{
		if (*buff == '\n')
		{
			if (width != save_width && save_width != 0)
				return (-1);
			height++;
			save_width = width;
			width = 0;
		}
		else if (*buff != '1' && *buff != '0' && *buff != 'C' && *buff != 'E' && *buff != 'P')
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
	char	tmp[1];
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
		if (read(fd, tmp, 1) < 0 || *tmp != '\n')
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
