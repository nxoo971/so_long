/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:09:02 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/24 19:30:17 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_data *data)
{
	int			i;
	static char	*paths[SIZE_PATH] = {
		"./sprites/wall1.xpm", "./sprites/door2.xpm", "./sprites/floor2.xpm",
		"./sprites/jm.xpm", "./sprites/item.xpm", "./sprites/bloc_vert.xpm",
		"./sprites/bloc_rouge.xpm", "./sprites/bloc_jaune.xpm",
		"./sprites/bloc_bleu.xpm",
	};

	i = -1;
	if (!data->img[0])
	{
		while (++i < SIZE_PATH)
		{
			data->img[i] = mlx_xpm_file_to_image(data->mlx, paths[i], \
				& data->width, & data->height);
			if (!data->img[i])
			{
				ft_printf("{red}Missing sprites{reset}\n");
				if (i == 0)
					i -= 2;
				return (free_mlx(*data, i) - 1);
			}
		}
	}
	return (1);
}
