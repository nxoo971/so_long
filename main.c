/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/20 18:39:28 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "mlx/mlx/mlx.h"
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_wall(t_map map, t_info info, void *mlx, void *mlx_win)
{
	(void)map;
	(void)mlx_win;
	info.data.img = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &info.img_width, &info.img_height);
	info.data.addr = mlx_get_data_addr(info.data.img, &info.data.bits_per_pixel, &info.data.line_length,
									&info.data.endian);
	for (int i = 0, a = 0; i < map.height * 16 && a < map.height; i += 16, a++) {
		for (int j = 0, b = 0; j < map.width * 16 && b < map.width; j += 16, b++) {
			ft_printf("{red}x: %d | y: %d{reset}\n", j / 16, i / 16);
			if (map.map[i / 16][j / 16] == WALL)
				mlx_put_image_to_window(mlx, mlx_win, info.data.img, j, i);
		}
	}
	ft_printf("\ntst\n");
}

int	main(int ac, char **av)
{
	static t_map	map = {
		.start_y = -1,
		.start_x = -1,
		
		.exit_y = -1,
		.exit_x = -1,

		.test = 1,
	};

	if (ac == 2)
	{
		map.filename = av[1];
		if (!valid_extension(map.filename))
			return (ft_printf("{blue}Wrong extension name\n{reset}"));
		if (parse_map(& map) < 0)
			return (ft_printf("{magenta}Error while parsing map\n{reset}"));
		if (valid_map(& map) <= 0)
			return (ft_printf("{magenta}Wrong map\n{reset}"));
		while (map.test)
			find_valid_path(& map);
		if (map.map[map.exit_y][map.exit_x] == '*') {
			for (int i = 0; i < map.height; i++) {
				if (ft_strchr(map.map[i], ITEM))
					return (ft_printf("{yellow}Can't collect all collectibles\n{reset}"));
			}	
			print_map(map);
		}
		else
			return (ft_printf("{yellow}Wrong path between P and E\n{reset}"));
		// remove all starts and set map as default
		if (parse_map(& map) < 0)
			return (ft_printf("{gray}Unknown error\n{reset}"));
		ft_putchar('\n');
		print_map(map);

		void	*mlx;
		void	*mlx_win;
		t_info	info;

		mlx = mlx_init();			// l    L
		mlx_win = mlx_new_window(mlx, map.width * 16, map.height * 16, "Hello world!");
		draw_wall(map, info, mlx, mlx_win);
		mlx_loop(mlx);
	}
	else
		return (ft_printf("{red}Wrong arguments\n{reset}"));
	return (0);
}