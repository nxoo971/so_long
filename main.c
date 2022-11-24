/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:30:40 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/24 20:22:20 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(const t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			ft_putchar(map.map[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

int	key_hook(int keycode, t_data *data)
{
	int			save;

	save = data->move_count;
	if (keycode == TOP || keycode == W)
		data->move_count += move_vertical(data, -1);
	if (keycode == DOWN || keycode == S)
		data->move_count += move_vertical(data, 1);
	if (keycode == LEFT || keycode == A)
		data->move_count += move_horizontal(data, -1);
	if (keycode == RIGHT || keycode == D)
		data->move_count += move_horizontal(data, 1);
	if (keycode == ESC || keycode == CLOSE)
		return (mlx_loop_end(data->mlx));
	if (save != data->move_count \
		&& data->map.map[data->map.exit_y][data->map.exit_x] != BLANK)
		ft_printf("Move count: %d\n", data->move_count);
	return (1);
}

int	launch_game(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		return (memdelarr(data.map.map));
	data.win = mlx_new_window(data.mlx, data.map.width * SPRITESIZE, \
		data.map.height * SPRITESIZE, "Play the game !");
	if (!data.win)
	{
		free(data.mlx);
		return (memdelarr(data.map.map));
	}
	if (!draw_wall(& data))
	{
		free_mlx(data, 0);
		memdelarr(data.map.map);
		return (0);
	}
	mlx_hook(data.win, .5, 1UL << 0, & key_hook, & data);
	mlx_key_hook(data.win, & key_hook, & data);
	mlx_loop(data.mlx);
	free_mlx(data, -1);
	memdelarr(data.map.map);
	return (0);
}

int	main(int ac, char const **av)
{
	static t_data	data = {
		.map.test = -1,
		.map.start_y = -1,
		.map.start_x = -1,
		.map.exit_y = -1,
		.map.exit_x = -1,
		.map.height = -1,
		.map.width = -1,
		.map.map = 0,
		.move_count = 0
	};

	if (ac != 2)
		return (ft_printf("{red}Wrong arguments\n{reset}"));
	data.map.filename = av[1];
	if (potential_errors(& data) != -1)
	{
		if (data.map.map != 0)
			memdelarr(data.map.map);
		return (0);
	}
	launch_game(data);
	return (0);
}
