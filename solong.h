/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:41:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/22 22:00:41 by jewancti         ###   ########.fr       */
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

# define	BLOC_GREEN	5
# define	BLOC_RED	6
# define	BLOC_YELLOW	7
# define	BLOC_BLUE	8

enum {
	ESC		= 65307,

	LEFT	= 65361,
	TOP		= 65362,
	RIGHT	= 65363,
	DOWN	= 65364,

	_START	= 3,
	_EXIT	= 1,
	_WALL	= 0,
	_BLANK	= 2,
	_ITEM	= 4,
	_BLOCK	= 5
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


typedef struct	s_data {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*chooseplayer;
	void	*img[256];
	char	*addr[256];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		index_perso;
	t_map	map;
}				t_data;

//	free.c
void	memdel(char **ptr);
void	memdelarr(char **arr);
void	print_map(const t_map map);
t_bool	valid_extension(const char *filename);
t_bool	valid_map(t_map *map);

void	virus(int y, int x, t_map *map);
int	find_valid_path(t_map *data);
int		get_sizemap(int fd, t_map *map);
int		set_map(t_map *map);
int		parse_map(t_map *map);

#endif
