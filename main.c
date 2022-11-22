/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/22 22:05:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "mlx/mlx/mlx.h"
#include "mlx/mlx/mlx_int.h"
#include "solong.h"
#include <time.h>

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

int	load_images(t_data *data)
{
	static char	*paths[9] = {
		"./sprites/walldy.xpm",
		"./sprites/door2.xpm",
		"./sprites/floor2.xpm",
		"./sprites/mgamil.xpm",
		"./sprites/item.xpm",
		"./sprites/bloc_vert.xpm",
		"./sprites/bloc_rouge.xpm",
		"./sprites/bloc_jaune.xpm",
		"./sprites/bloc_bleu.xpm",
	};
	if (!data->img[0]) { // usleep
		for (int i = 0; i < 9; i++) {
			data->img[i] = mlx_xpm_file_to_image(data->mlx, paths[i], & data->width, & data->height);
			if (!data->img[i])
				return -1; // free ceux auparavant
		}
	}
	return 1;
}

void	draw_wall(t_data *data)
{
	int	y;
	int	x;
	//static const int	item[2] = {3, 5};
	if (load_images(data) < 0)
		return ;
	for (int i = 1; i < data->map.height * SPRITESIZE; i += SPRITESIZE) {
		for (int j = 1; j < data->map.width * SPRITESIZE; j += SPRITESIZE) {
			y = i / SPRITESIZE;
			x = j / SPRITESIZE;
			if (data->map.map[y][x] == WALL) {
				if (y == 0 || (y > 0 && x == 0) || (y == data->map.height - 1) || (y > 0 && x == data->map.width - 1))
					mlx_put_image_to_window(data->mlx, data->win, data->img[0], j, i);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->img[(rand() % (BLOC_BLUE - BLOC_GREEN + 1)) + BLOC_GREEN], j, i);
			}
			if (data->map.map[y][x] == EXIT)
				mlx_put_image_to_window(data->mlx, data->win, data->img[1], j, i);
			if (data->map.map[y][x] == BLANK)
				mlx_put_image_to_window(data->mlx, data->win, data->img[2], j, i);
			if (data->map.map[y][x] == START)
				//mlx_put_image_to_window(data->mlx, data->win, data->img[item[(rand() % (1 - 0 + 1)) + 0]], j, i);
				mlx_put_image_to_window(data->mlx, data->win, data->img[3], j, i);
			if (data->map.map[y][x] == ITEM)
				mlx_put_image_to_window(data->mlx, data->win, data->img[4], j, i);
		}
	}
}

void	draw(t_data *data, int y, int x, int imgcode)
{
	if (data->img[imgcode])
		mlx_put_image_to_window(data->mlx, data->win, data->img[imgcode], x * SPRITESIZE, y * SPRITESIZE);
}

int	collectibles(t_map map)
{
	for (int y = 0; y < map.height; y++) {
		if (ft_strchr(map.map[y], ITEM))
			return (0);
	}
	return (1);
}

void	move_vertical(t_data *data, int add)
{
	if (data->map.map[data->map.start_y + add][data->map.start_x] != WALL)
	{
		if (data->map.map[data->map.start_y + add][data->map.start_x] == EXIT) {
			if (collectibles(data->map)) {
				ft_printf("\n{bgyellow}%d{reset}\n", collectibles(data->map));
				mlx_loop_end(data->mlx);
			}
			else {
				ft_printf("{bgblue}hee{reset}\n");
				mlx_string_put(data->mlx, data->win, (data->map.start_y / 2) * SPRITESIZE, (data->map.start_x / 2) * SPRITESIZE, 0xFF, "Prend tous les collectibles FDP");
				print_map(data->map);
				return ;
			}
		}
		data->map.map[data->map.start_y][data->map.start_x] = BLANK;
		data->map.map[data->map.start_y + add][data->map.start_x] = START;

		draw(data, data->map.start_y, data->map.start_x, _BLANK);
		draw(data, data->map.start_y + add, data->map.start_x, _START);
		data->map.start_y += add;
		print_map(data->map);
	}
}

void	move_horizontal(t_data *data, int add)
{
	if (data->map.map[data->map.start_y][data->map.start_x + add] != WALL)
	{
		if (data->map.map[data->map.start_y][data->map.start_x + add] == EXIT) {
			if (/*no_*/collectibles(data->map)) {
				mlx_loop_end(data->mlx);
			}
			else {
				mlx_string_put(data->mlx, data->win, data->map.start_y / 2, data->map.start_x / 2, 0xFF, "Prend tous les collectibles FDP");
				print_map(data->map);
				return ;
			}
		}
		data->map.map[data->map.start_y][data->map.start_x] = BLANK;
		data->map.map[data->map.start_y][data->map.start_x + add] = START;

		draw(data, data->map.start_y, data->map.start_x, _BLANK);
		draw(data, data->map.start_y, data->map.start_x + add, _START);

		data->map.start_x += add;
		print_map(data->map);
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
		return (mlx_loop_end(data->mlx));
	return (1);
}

int test(char *filename)
{
	t_data data = {
		.map.test = -1,

		.map.start_y = -1,
		.map.start_x = -1,

		.map.exit_y = -1,
		.map.exit_x = -1,

		.map.height = -1,
		.map.width = -1,
	};
	
	data.map.filename = filename;
	if (!valid_extension(data.map.filename))
		return (ft_printf("{blue}Wrong extension name\n{reset}"));
	if (parse_map(& data.map) < 0)
		return (ft_printf("{magenta}Error while parsing map\n{reset}"));
	ft_printf("{bgred}tst{reset}\n");
	print_map((const t_map)data.map);
	if (valid_map(& data.map) <= 0) {
		memdelarr(data.map.map);
		return (ft_printf("{magenta}Wrong map\n{reset}"));
	}
	while (data.map.test)
		find_valid_path(& data.map);
	if (data.map.map[data.map.exit_y][data.map.exit_x] == '*') {
		for (int i = 0; i < data.map.height; i++) {
			if (ft_strchr(data.map.map[i], ITEM)) {
				memdelarr(data.map.map);
				return (ft_printf("{yellow}Can't collect all collectibles\n{reset}"));
			}
		}	
	}
	else {
		memdelarr(data.map.map);
		return (ft_printf("{yellow}Wrong path between P and E\n{reset}"));
	}
	// remove all starts and set map as default
	memdelarr(data.map.map);
	if (parse_map(& data.map) < 0) {
		memdelarr(data.map.map);
		return (ft_printf("{gray}Unknown error\n{reset}"));
	}
	// init random func
	srand(time(0));
	data.mlx = mlx_init();
	if (!data.mlx) {
		memdelarr(data.map.map);
		return (-1);
	}
	data.win = mlx_new_window(data.mlx, data.map.width * SPRITESIZE, data.map.height * SPRITESIZE, "Choose a player!");
	if (!data.win) {
		memdelarr(data.map.map);
		return (-1);
	}
	draw_wall(&data);
	mlx_hook(data.win, .5, 1L << 0, & key_hook, &data);
	mlx_key_hook(data.win, & key_hook, &data);
	mlx_loop(data.mlx);
	for (int i = 0; i <= 8; i++)
		mlx_destroy_image(data.mlx, data.img[i]);
   	mlx_clear_window(data.mlx, data.win);
   	mlx_destroy_window(data.mlx,data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	memdelarr(data.map.map);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("{red}Wrong arguments\n{reset}"));;
	
	if (test(av[1]) != 0)
		return (-1);
	if (test("b.ber") != 0)
		return (-1);
	return (0);
}
