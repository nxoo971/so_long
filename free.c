/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:46:04 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 16:09:05 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	memdel(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

int	memdelarr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		memdel(& arr[i]);
	free(arr);
	return (0);
}

int	free_mlx(t_data data, int index, int end)
{
	int	i;
	int	max;

	i = -1;
	max = index;
	if (max == -1)
		max = end;
	while (++i < max)
		mlx_destroy_image(data.mlx, data.img[i]);
	if (index != 0)
	{
		mlx_clear_window(data.mlx, data.win);
		mlx_destroy_window(data.mlx, data.win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		data.mlx = 0;
	}
	return (0);
}
