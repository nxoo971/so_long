/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/11/14 14:51:49 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static \
int	print_width_precision(const struct s_spec_info *s)
{
	int	width;
	int	c;

	c = ' ';
	if (s->with_leading_zeroes)
	{
		if (!s->is_left_aligned)
			c = '0';
	}
	width = (s->width - s->current_size);
	if (s->width > 0 && s->precision_is_specified && \
			(s->precision == -1 || s->width > s->precision))
	{
		width = s->width;
		if (s->width > s->precision && s->precision != -1)
		{
			if (s->precision > s->current_size)
				width -= s->current_size;
			else
				width -= s->precision;
		}
		return (print_width(width, c));
	}
	return (print_width(width, c));
}

int	exec_char(va_list *param, struct s_spec_info *s)
{
	s->current_size = 1;
	if (s->is_left_aligned)
		return (ft_putchar(va_arg(*param, int)) \
					+ print_width_precision(s));
	return (print_width_precision(s) + \
				ft_putchar(va_arg(*param, int)));
}

int	exec_percent(va_list *param, struct s_spec_info *s)
{
	(void)param;
	s->current_size = 1;
	if (s->is_left_aligned)
		return (ft_putchar('%') + print_width_precision(s));
	return (print_width_precision(s) + ft_putchar('%'));
}

int	exec_string(va_list *param, struct s_spec_info *s)
{
	const char	*str;
	int			written;

	str = va_arg(*param, const char *);
	if (!str)
		str = "(null)";
	s->current_size = ft_strlen(str);
	written = 0;
	if (s->space && !s->is_left_aligned && s->current_size > 0 && !*str)
		written = ft_putchar(' ');
	if (!s->is_left_aligned)
		written += print_width_precision(s);
	if (s->precision_is_specified)
	{
		if (s->precision == -1 && !s->is_left_aligned)
			return (written);
		if (s->precision == -1 && s->is_left_aligned)
			return (print_width_precision(s));
		if (s->is_left_aligned)
			return (ft_putnstr(str, s->precision) + print_width_precision(s));
		return (written + ft_putnstr(str, s->precision));
	}
	if (!s->is_left_aligned)
		return (written + ft_putstr(str));
	return (ft_putstr(str) + print_width_precision(s));
}
