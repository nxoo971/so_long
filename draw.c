/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:04:53 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 05:25:05 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	set_images(t_data *data, int y, int x)
{
	//ft_printf("\n{red}%d|%d{reset}\n", y, x);
	if (data->map.map[y][x] == WALL)
	{
		if (y == 0 || (y > 0 && x == 0) || (y == data->map.height - 1) \
			|| (y > 0 && x == data->map.width - 1))
			draw(data, y, x, _WALL);
		else
			draw(data, y, x, _BLOCK);
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
	print_count(data, data->move_count);
	return (1);
}

int	draw_main_lobby(t_data *data)
{
	int	y;
	int	x;
	if (load_images_bonus(data) < 0)
		return (0);

	mlx_put_image_to_window(data->mlx, data->win, data->img[SIZE_PERSO - 1], 0, 0);
	int start = ((1007 - (SPRITESIZE * (SIZE_PERSO - 1))) / 2) - ((SPRITESIZE * (SIZE_PERSO - 2)) / 2);
	for (int i = 0; i < SIZE_PERSO - 1; i++)
	{
		x = start + (64 * i);
		y = 640 / 2 + 96;
		data->point_img[i][0] = y / 32;
		data->point_img[i][1] = x / 32;
		//mlx_put_image_to_window(data->mlx, data->win, data->img[i], x, y);
	}
	draw(data, data->map.start_y, data->map.start_x, Moha);
	return (1);
}

int	draw_bonus(t_data *data)
{
	int	y;
	int	x;
	if (load_images_bonus(data) < 0)
		return (0);

	mlx_put_image_to_window(data->mlx, data->win, data->img[SIZE_PERSO - 1], 0, 0);
	int start = ((1007 - (SPRITESIZE * (SIZE_PERSO - 1))) / 2) - ((SPRITESIZE * (SIZE_PERSO - 2)) / 2);
	for (int i = 0; i < SIZE_PERSO - 1; i++)
	{

		x = start + (64 * i);
		y = 640 / 2 + 96;
		data->point_img[i][0] = y / 32;
		data->point_img[i][1] = x / 32;
		mlx_put_image_to_window(data->mlx, data->win, data->img[i], x, y);
	}
	draw(data, data->map.start_y, data->map.start_x, Moha);
	return (1);
}

int	draw(t_data *data, int y, int x, int imgcode)
{
	//ft_printf("\n{blue}%d|%d - %d{reset}\n", y, x,imgcode);
	if (data->img[imgcode] && imgcode < SIZE_PERSO - 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img[imgcode], x * SPRITESIZE, y * SPRITESIZE);
		return (1);
	}
	return (0);
}
