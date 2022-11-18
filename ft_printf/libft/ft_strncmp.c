/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:09:02 by ooxn              #+#    #+#             */
/*   Updated: 2022/11/18 18:06:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*copy;
	unsigned char	*copy2;

	copy = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	while (*copy || *copy2)
	{
		if (*copy != *copy2)
			return (*copy - *copy2);
		copy++;
		copy2++;
	}
	return (0);
}
