/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/20 14:37:13 by jewancti         ###   ########.fr       */
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
	static t_map	map = {
		.start_y = -1,
		.start_x = -1,
		
		.exit_y = -1,
		.exit_x = -1,

		.test = 1,
	};

	if (ac == 2)
	{
		map.filename = av[1];
		if (!valid_extension(map.filename))
			return (-1);
		if (parse_map(& map) < 0)
			return (-1);
		if (valid_map(& map) <= 0)
			return (-1);
		while (map.test)
			find_valid_path(& map);
		if (map.map[map.exit_y][map.exit_x] == '*')
			print_map(map);
		else
		return (ft_printf("{yellow}Wrong path\n{reset}"));
	}
	else
		return (ft_printf("{red}Wrong arguments\n{reset}"));
	return (0);
}