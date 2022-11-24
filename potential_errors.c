/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potential_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:35:03 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/24 19:35:40 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_data *data)
{
	int	i;

	i = -1;
	while (data->map.test)
		find_valid_path(& data->map);
	if (data->map.map[data->map.exit_y][data->map.exit_x] == '*')
	{
		while (++i < data->map.height)
		{
			if (ft_strchr(data->map.map[i], ITEM))
			{
				memdelarr(data->map.map);
				return (\
				ft_printf("{yellow}Can't collect all collectibles\n{reset}"));
			}
		}
		return (0);
	}
	memdelarr(data->map.map);
	data->map.map = 0;
	return (ft_printf("{yellow}Wrong path between P and E\n{reset}"));
}

int	potential_errors(t_data *data)
{
	if (!valid_extension(data->map.filename))
		return (ft_printf("{blue}Wrong extension name\n{reset}"));
	if (parse_map(& data->map) == 0)
		return (ft_printf("{magenta}Error while parsing map\n{reset}"));
	if (valid_map(& data->map) == 0)
	{
		memdelarr(data->map.map);
		data->map.map = 0;
		return (ft_printf("{magenta}Wrong map\n{reset}"));
	}
	if (valid_path(data) != 0)
		return (1);
	memdelarr(data->map.map);
	if (parse_map(& data->map) < 0)
	{
		memdelarr(data->map.map);
		return (ft_printf("{gray}Unknown error\n{reset}"));
	}
	return (-1);
}
