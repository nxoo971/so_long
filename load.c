/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:09:02 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 04:57:11 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

int	load_images(t_data *data)
{
	int			i;
	static char	*paths[SIZE_PATH] = {
		"./sprites/mandatory/wall1.xpm", "./sprites/mandatory/door2.xpm", "./sprites/mandatory/floor2.xpm",
		"./sprites/mandatory/jm.xpm", "./sprites/mandatory/item.xpm", "./sprites/mandatory/bloc_vert.xpm", "./sprites/bonus/0.xpm", "./sprites/bonus/1.xpm", "./sprites/bonus/2.xpm", "./sprites/bonus/3.xpm",
		"./sprites/bonus/4.xpm", "./sprites/bonus/5.xpm", "./sprites/bonus/6.xpm", "./sprites/bonus/7.xpm",
		"./sprites/bonus/8.xpm", "./sprites/bonus/9.xpm"
	};

	if (!data->img[0])
	{
		i = -1;
		while (++i < SIZE_PATH)
		{
			data->img[i] = mlx_xpm_file_to_image(data->mlx, paths[i], \
				& data->width[i], & data->height[i]);
			if (!data->img[i])
			{
				ft_printf("{red}Missing sprites ({green}%s {red}or maybe corrupted?){reset}\n", paths[i]);
				if (i == 0)
					i -= 2;
				return (free_mlx(*data, i, SIZE_PATH) - 1);
			}
		}
	}
	return (1);
}

int	load_images_bonus(t_data *data)
{
	int			i;
	static char	*paths[SIZE_PERSO] = {
		"./sprites/bonus/gab_x32.xpm", "./sprites/bonus/isaac_x32.xpm", "./sprites/bonus/jm_x32.xpm",
		"./sprites/bonus/leo_x32.xpm", "./sprites/bonus/margaux_x32.xpm", "./sprites/bonus/maxou_x32.xpm",
		"./sprites/bonus/moha_x32.xpm", "./sprites/bonus/rayan_x32.xpm", MAIN_IMAGE
	};

	i = -1;
	if (!data->img[0])
	{
		while (++i < SIZE_PERSO)
		{
			if (paths[i])
				data->img[i] = mlx_xpm_file_to_image(data->mlx, paths[i], \
					& data->width[i], & data->height[i]);
			if (!data->img[i])
			{
				ft_printf("{red}Missing sprites ({green}%s {red}or maybe corrupted?){reset}\n", paths[i]);
				if (i == 0)
					i -= 2;
				memdelarr(data->map.map);
				return (free_mlx(*data, i, SIZE_PERSO) - 1);
			}
		}
	}
	return (1);
}
