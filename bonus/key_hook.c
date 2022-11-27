/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:37:30 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 16:46:35 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_count(t_data *data, int counter)
{
	static int	i = 0;

	mlx_put_image_to_window(data->mlx, data->win, \
		data->img[(10 + counter % 10)], \
		((data->width[SIZE_PATH - 2] * 32) / 2) - (32 * i), 0);
	i += 1;
	if (counter > 9)
		print_count(data, counter / 10);
	i = 0;
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
		&& (data->map.map[data->map.exit_y][data->map.exit_x] != BLANK \
		|| (data->map.start_x != data->map.exit_x \
		|| data->map.exit_y != data->map.start_y)))
		print_count(data, data->move_count);
	return (1);
}
