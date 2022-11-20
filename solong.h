/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:41:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/20 09:18:08 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define	START	'P'
# define	EXIT	'E'
# define	WALL	'1'
# define	BLANK	'0'
# define	ITEM	'C'

typedef struct s_map
{
	char	**map;
	char	*filename;
	// window size
	int		width;
	int		height;

	int		walls;
	int		items;
	int		blanks;
	// START P point
	int		y;
	int		x;

	// ????
	int		test;
} t_map;

t_bool	valid_extension(const char *filename);
t_bool	valid_map(t_map *map);

void	virus(int y, int x, t_map *map);
int		find_valid_path(t_map *map);
int		get_sizemap(int fd, t_map *map);
int		set_map(t_map *map);
int		parse_map(t_map *map);

#endif
