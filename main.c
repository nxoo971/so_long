/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/21 10:28:13 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "mlx/mlx/mlx.h"
#include "mlx/mlx/mlx_int.h"
#include "solong.h"

void	print_map(const t_map map)
{
	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
			ft_putchar(map.map[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	load_images(t_data *data)
{
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./sprites/wall1.xpm", & data->info.img_width, & data->info.img_height);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./sprites/exit.xpm", & data->info.img_width, & data->info.img_height);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./sprites/floor.xpm", & data->info.img_width, & data->info.img_height);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./sprites/mgamil.xpm", & data->info.img_width, & data->info.img_height);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./sprites/item.xpm", & data->info.img_width, & data->info.img_height);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "./sprites/jewancti.xpm", & data->info.img_width, & data->info.img_height);
}

void	draw_wall(t_data data)
{
	int	y;
	int	x;
	static int a = 0;
	load_images(& data);
	for (int i = 0; i < data.map.height * SPRITESIZE; i += SPRITESIZE) {
		for (int j = 0; j < data.map.width * SPRITESIZE; j += SPRITESIZE) {
			y = i / SPRITESIZE;
			x = j / SPRITESIZE;
			if (data.map.map[y][x] == WALL)
				mlx_put_image_to_window(data.mlx, data.win, data.img[0], j, i);
			if (data.map.map[y][x] == EXIT)
				mlx_put_image_to_window(data.mlx, data.win, data.img[1], j, i);
			if (data.map.map[y][x] == BLANK)
				mlx_put_image_to_window(data.mlx, data.win, data.img[2], j, i);
			if (data.map.map[y][x] == START) {
				if (a % 2)
					mlx_put_image_to_window(data.mlx, data.win, data.img[3], j, i);
				else
					mlx_put_image_to_window(data.mlx, data.win, data.img[5], j, i);
				a++;
			}
			if (data.map.map[y][x] == ITEM)
				mlx_put_image_to_window(data.mlx, data.win, data.img[4], j, i);
		}
	}
}

void	move_vertical(t_data *data, int add)
{
	if (data->map.map[data->map.start_y + add][data->map.start_x] != WALL)
	{
		data->map.map[data->map.start_y][data->map.start_x] = '0';
		data->map.map[data->map.start_y + add][data->map.start_x] = START;
		data->map.start_y += add;
		print_map(data->map);
		draw_wall(*data);
	}
}

void	move_horizontal(t_data *data, int add)
{
	if (data->map.map[data->map.start_y][data->map.start_x + add] != WALL)
	{
		data->map.map[data->map.start_y][data->map.start_x] = '0';
		data->map.map[data->map.start_y][data->map.start_x + add] = START;
		data->map.start_x += add;
		print_map(data->map);
		draw_wall(*data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == TOP)
		move_vertical(data, -1);
	if (keycode == DOWN)
		move_vertical(data, 1);
	if (keycode == LEFT)
		move_horizontal(data, -1);
	if (keycode == RIGHT)
		move_horizontal(data, 1);
	if (keycode == ESC)
		mlx_loop_end(data->mlx);
	return (1);
}
#include "mlx/mlx/mlx_int.h"
int	main(int ac, char **av)
{
	static t_data data = {
		.map.test = -1,

		.map.start_y = -1,
		.map.start_x = -1,

		.map.exit_y = -1,
		.map.exit_x = -1,

		.map.height = -1,
		.map.width = -1
	};

	if (ac == 2)
	{
		data.map.filename = av[1];
		data.map.test = 1;
		data.map.test = 1;
		data.map.test = 1;
		if (!valid_extension(data.map.filename))
			return (ft_printf("{blue}Wrong extension name\n{reset}"));
		if (parse_map(& data.map) < 0)
			return (ft_printf("{magenta}Error while parsing map\n{reset}"));
		if (valid_map(& data.map) <= 0)
			return (ft_printf("{magenta}Wrong map\n{reset}"));
		while (data.map.test)
			find_valid_path(& data.map);
		if (data.map.map[data.map.exit_y][data.map.exit_x] == '*') {
			for (int i = 0; i < data.map.height; i++) {
				if (ft_strchr(data.map.map[i], ITEM))
					return (ft_printf("{yellow}Can't collect all collectibles\n{reset}"));
			}	
		}
		else
			return (ft_printf("{yellow}Wrong path between P and E\n{reset}"));
		// remove all starts and set map as default
		if (parse_map(& data.map) < 0)
			return (ft_printf("{gray}Unknown error\n{reset}"));
		ft_putchar('\n');
		data.mlx = mlx_init();			// l    L
		ft_printf("%i %i\n" , data.map.width * SPRITESIZE, data.map.height * SPRITESIZE);
		data.win = mlx_new_window(data.mlx, data.map.width * SPRITESIZE, data.map.height * SPRITESIZE, "Hello world!");
		data.img[0] = mlx_xpm_file_to_image(data.mlx, "./sprites/jewancti.xpm", &data.info.img_height, &data.info.img_height);
		mlx_put_image_to_window(data.mlx, data.win, data.img[0], 0, 0);
		draw_wall(data);

		//mlx_do_key_autorepeaton(data.mlx);
		//mlx_mouse_hide(data.mlx, data.win);
		mlx_string_put(data.mlx,data.win, 100,242/2,0xFF99FF,"plante les");
		//mlx_string_put(data.mlx, data.win, 100, 100, 0xd2691e, "plante les");
		//mlx_key_hook(data.win, 0, & data);
		mlx_hook(data.win, .1, 1L<<0, & key_hook, &data);
		//ft_printf("\nbefore: %p | %p\n", data.mlx, data.win);
		mlx_key_hook(data.win, & key_hook, &data);
		//ft_printf("\nafter: %p | %p\n", data.mlx, data.win);
		mlx_loop(data.mlx);
	}
	else
		return (ft_printf("{red}Wrong arguments\n{reset}"));
	return (0);
}