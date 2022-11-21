/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:41:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/21 10:21:44 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define	START		'P'
# define	EXIT		'E'
# define	WALL		'1'
# define	BLANK		'0'
# define	ITEM		'C'
# define	SPRITESIZE	32

enum {
	ESC		= 65307,

	LEFT	= 65361,
	TOP		= 65362,
	RIGHT	= 65363,
	DOWN	= 65364
};

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
	int		start_y;
	int		start_x;
	// EXIT E point
	int		exit_y;
	int		exit_x;

	// ????
	int		test;
} t_map;

typedef struct	s_info {
	int		img_width;
	int		img_height;
}				t_info;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img[256];
	char	*addr[256];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_info	info;
	t_map	map;
}				t_data;

void	print_map(const t_map map);
t_bool	valid_extension(const char *filename);
t_bool	valid_map(t_map *map);

void	virus(int y, int x, t_map *map);
int	find_valid_path(t_map *data);
int		get_sizemap(int fd, t_map *map);
int		set_map(t_map *map);
int		parse_map(t_map *map);

#endif
