/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:37:30 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 05:38:54 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	print_count(t_data *data, int counter)
{
	static int i = 0;
	int	index;
	int	y;
	int	x;

	index = data->move_count - i;
	//if (counter > 9)
	//	print_count(data, counter % 10);

	//int start = ((1007 - (SPRITESIZE * (4 - 1))) / 2) - ((SPRITESIZE * (4 - 1)) / 2);
	x = 50;
	y = 50;
	ft_printf("\ntst\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img[6 + counter % 10], ((data->width[SIZE_PERSO - 1] * 32) / 2) - (32 * i), 640 + 32 * 3);
	i += 1;
	if (counter > 9)
		print_count(data, counter / 10);
	i = 0;
	//for (int i = 0; i < SIZE_PERSO - 1; i++)
	//{
	//	x = start + (64 * i);
	//	y = 640 - 32;
	//	data->point_img[i][0] = y / 32;
	//	data->point_img[i][1] = x / 32;
	//	//mlx_put_image_to_window(data->mlx, data->win, data->img[i], x, y);
	//}
}

int	key_hook_bonus(int keycode, t_data *data)
{
	int			save;

	save = data->move_count;
	if (keycode == TOP || keycode == W)
		data->move_count += move_vertical_bonus(data, -1);
	if (keycode == DOWN || keycode == S)
		data->move_count += move_vertical_bonus(data, 1);
	if (keycode == LEFT || keycode == A)
		data->move_count += move_horizontal_bonus(data, -1);
	if (keycode == RIGHT || keycode == D)
		data->move_count += move_horizontal_bonus(data, 1);
	if (keycode == ESC || keycode == CLOSE)
		return (mlx_loop_end(data->mlx));
	if (save != data->move_count \
		&& data->map.map[data->map.exit_y][data->map.exit_x] != BLANK)
		{
			//print_count(data, data->move_count, 3);
			ft_printf("Move count: %d\n", data->move_count);
		}
	return (1);
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
		ft_printf("Move count: %d\n", data->move_count);
	return (1);
}
