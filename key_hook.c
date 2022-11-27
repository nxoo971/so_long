/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:37:30 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 16:05:39 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf("Move count: %d\n", data->move_count);
	return (1);
}
