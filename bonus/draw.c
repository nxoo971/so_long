/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:04:53 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 15:51:55 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_data *data, int y, int x)
{
	static const int	txt[3] = {_BLOCK, 9, 8};

	if (data->map.map[y][x] == WALL)
	{
		if (y == 0 || (y > 0 && x == 0) || (y == data->map.height - 1) \
			|| (y > 0 && x == data->map.width - 1))
			draw(data, y, x, _WALL);
		else
			draw(data, y, x, txt[(rand() % (2 - 0 + 1)) + 0]);
	}
	if (data->map.map[y][x] == EXIT)
	{
		if (no_collectibles(data->map))
			draw(data, y, x, _EXIT);
		else
			draw(data, y, x, _BLANK);
	}
	if (data->map.map[y][x] == BLANK)
		draw(data, y, x, _BLANK);
	if (data->map.map[y][x] == START)
		draw(data, y, x, _START);
	if (data->map.map[y][x] == ITEM)
		draw(data, y, x, _ITEM);
	if (data->map.map[y][x] == 'K')
		draw(data, y, x, 7);
}

int	draw_wall(t_data *data)
{
	int	y;
	int	x;
	int	i;
	int	j;

	if (load_images(data) < 0)
		return (0);
	i = 0;
	while (++i < data->map.height * SPRITESIZE)
	{
		j = 0;
		while (++j < data->map.width * SPRITESIZE)
		{
			y = i / SPRITESIZE;
			x = j / SPRITESIZE;
			set_images(data, y, x);
			j += SPRITESIZE - 1;
		}
		i += SPRITESIZE - 1;
	}
	return (1);
}

int	draw(t_data *data, int y, int x, int imgcode)
{
	if (data->img[imgcode])
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img[imgcode], x * SPRITESIZE, y * SPRITESIZE);
		return (1);
	}
	return (0);
}
