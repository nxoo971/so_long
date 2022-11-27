/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:02:58 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/26 18:40:46 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

static \
t_bool	touched(t_data *data, int y, int x)
{
	
	for (int i = 0; i < SIZE_PERSO; i++)
	{
		if (data->point_img[i][0] == y \
			&& data->point_img[i][1] == x)
		{
			data->index_perso = i;
			return (vrai);
		}
	}
	return (faux);
}

int	move_vertical_bonus(t_data *data, int add)
{
	if (touched(data, data->map.start_y + add, data->map.start_x))
	{
		mlx_loop_end(data->mlx);
		return (ft_printf("{bgred}\n\t\t\t\t\tPerso\vselected{reset}\n"));
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
		data->map.start_y += add;
		draw_bonus(data);
		return (1);
	}
	return (0);
}

int	move_horizontal_bonus(t_data *data, int add)
{
	if (touched(data, data->map.start_y, data->map.start_x + add))
	{
		mlx_loop_end(data->mlx);
		return (ft_printf("{bgred}\n\t\t\t\t\tPerso\vselected{reset}\n"));
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
		data->map.start_x += add;
		draw_bonus(data);
		return (1);
	}
	return (0);
}
