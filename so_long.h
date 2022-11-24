/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:30:47 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/24 19:29:58 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "mlx/mlx/mlx.h"

# define START			'P'
# define EXIT			'E'
# define WALL			'1'
# define BLANK			'0'
# define ITEM			'C'
# define SPRITESIZE		32

# define SIZE_PATH		9

# define BLOC_GREEN		5
# define BLOC_RED		6
# define BLOC_YELLOW	7
# define BLOC_BLUE		8

enum {
	CLOSE	= 17,
	ESC		= 65307,
	LEFT	= 65361,
	TOP		= 65362,
	RIGHT	= 65363,
	DOWN	= 65364,
	W		= 119,
	A		= 97,
	S		= 115,
	D		= 100,
	_START	= 3,
	_EXIT	= 1,
	_WALL	= 0,
	_BLANK	= 2,
	_ITEM	= 4,
	_BLOCK	= 5
};

typedef struct s_map
{
	char		**map;
	const char	*filename;

	int			width;
	int			height;

	int			walls;
	int			items;
	int			blanks;

	int			start_y;
	int			start_x;

	int			exit_y;
	int			exit_x;

	int			test;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;

	void	*chooseplayer;
	int		index_perso;
	int		move_count;

	void	*img[256];
	char	*addr[256];

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_map	map;
}				t_data;

//	free.c
void	memdel(char **ptr);
int		memdelarr(char **arr);
int		free_mlx(t_data data, int index);
//	potential_errors.c
int		potential_errors(t_data *data);
t_bool	valid_extension(const char *filename);
//	parser.c
int		parse_map(t_map *map);
//	valid_map.c
t_bool	valid_map(t_map *map);
//	virus.c
void	find_valid_path(t_map *map);
//	move.c
int		move_vertical(t_data *data, int add);
int		move_horizontal(t_data *data, int add);
//	draw.c
int		draw(t_data *data, int y, int x, int imgcode);
int		draw_wall(t_data *data);
int		load_images(t_data *data);
void	print_map(const t_map map);
int		no_collectibles(t_map map);
#endif