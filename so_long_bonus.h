/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:33:41 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/27 02:22:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

# define SIZE_PERSO	9
# define WIDTH		32
# define HEIGHT		32

# define MAIN_IMAGE	"./sprites/bonus/select.xpm"

enum Perso {
	Gab,
	Isaac,
	Jm,
	Leo,
	Margaux,
	Maxou,
	Moha,
	Rayan
};

int	load_images_bonus(t_data *data);
int	draw_main_lobby(t_data *data);
int	draw_bonus(t_data *data);
//	move_bonus.c
int		move_vertical_bonus(t_data *data, int add);
int		move_horizontal_bonus(t_data *data, int add);
//	key_hook.c
int		key_hook_bonus(int keycode, t_data *data);
#endif