/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:02:58 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 15:51:40 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*\*/
int	no_collectibles(t_map map)
{
	int	y;

	y = -1;
	while (++y < map.height)
	{
		if (ft_strchr(map.map[y], ITEM))
			return (0);
	}
	return (1);
}

int	move_vertical(t_data *data, int add)
{
	if (data->map.map[data->map.start_y + add][data->map.start_x] == 'K')
	{
		ft_printf("{bgred}You lose the game{reset}\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (data->map.map[data->map.start_y + add][data->map.start_x] != WALL)
	{
		if (data->map.map[data->map.start_y + add][data->map.start_x] == EXIT \
			&& no_collectibles(data->map))
		{
			ft_printf("{bggreen}Finished{reset}{green} with {reset}{red}"
				"%d{reset}{green} as counter{reset}\n", data->move_count + 1);
			data->map.map[data->map.exit_y][data->map.exit_x] = BLANK;
			mlx_loop_end(data->mlx);
			return (0);
		}
		data->map.map[data->map.start_y][data->map.start_x] = BLANK;
		data->map.map[data->map.start_y + add][data->map.start_x] = START;
		if (no_collectibles(data->map))
			data->map.map[data->map.exit_y][data->map.exit_x] = EXIT;
		draw_wall(data);
		data->map.start_y += add;
		return (1);
	}
	return (0);
}

int	move_horizontal(t_data *data, int add)
{
	if (data->map.map[data->map.start_y][data->map.start_x + add] == 'K')
	{
		ft_printf("{bgred}You lose the game{reset}\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (data->map.map[data->map.start_y][data->map.start_x + add] != WALL)
	{
		if (data->map.map[data->map.start_y][data->map.start_x + add] == EXIT \
			&& no_collectibles(data->map))
		{
			ft_printf("{bggreen}Finished{reset}{green} with {reset}{red}"
				"%d{reset}{green} as counter{reset}\n", data->move_count + 1);
			mlx_loop_end(data->mlx);
			return (0);
		}
		data->map.map[data->map.start_y][data->map.start_x] = BLANK;
		data->map.map[data->map.start_y][data->map.start_x + add] = START;
		if (no_collectibles(data->map))
			data->map.map[data->map.exit_y][data->map.exit_x] = EXIT;
		draw_wall(data);
		data->map.start_x += add;
		return (1);
	}
	return (0);
}

/**/