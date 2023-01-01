/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 23:18:30 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_integer(va_list *param, struct s_spec_info *s)
{
	intptr_t	n;
	int			written;

	written = 0;
	n = va_arg(*param, int);
	s->current_size = len_integer(n, 10);
	s->is_negative = n < 0;
	s->is_null = n == 0;
	if (s->is_negative)
		n = n * -1;
	if (s->space && !s->plus && !s->is_negative)
		written = ft_putchar(' ');
	return (written + print_algo_flag(s, n, 10, faux));
}
