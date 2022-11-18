/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/18 22:12:25 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "mlx/mlx/mlx.h"
#include "solong.h"

void	print_map(const t_map map)
{
	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
			ft_putchar(map.map[i][j]);
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map.filename = av[1];
		if (!valid_extension(map.filename))
			return (-1);
		if (parse_map(& map) < 0)
			return (-1);
		if (valid_map(map) <= 0)
			return (-1);
		print_map(map);
	}
	else
		return (ft_putstr("Wrong arguments\n"));
	return (0);
}