/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:41:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/18 21:59:06 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	int		walls;
	int		items;
	int		blanks;
	char	**map;
	char	*filename;
	int		width;
	int		height;
} t_map;

t_bool	valid_extension(char *filename);
t_bool	valid_map(t_map map);
int	get_sizemap(int fd, t_map *map);
int	set_map(t_map *map);
int	parse_map(t_map *map);

#endif
