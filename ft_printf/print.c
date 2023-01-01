/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:30:59 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 18:17:14 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix(const struct s_spec_info *s)
{
	static const int	current_type[2] = {'x', 'X'};
	int					written;

	written = 0;
	if ((s->sharp && !s->is_null) || s->current_type == 'p')
	{
		written += ft_putchar('0');
		written += ft_putchar(current_type[s->current_type == 'X']);
	}
	return (written);
}

int	print_sign(const struct s_spec_info *s)
{
	if (s->is_negative)
		return (ft_putchar('-'));
	if (s->plus && !s->is_negative)
		return (ft_putchar('+'));
	return (0);
}

int	print_width(int width, int c)
{
	int	written;

	written = 0;
	while (--width >= 0)
		written += ft_putchar(c);
	return (written);
}
