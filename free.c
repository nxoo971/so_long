/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:46:04 by jewancti          #+#    #+#             */
/*   Updated: 2022/11/22 02:46:24 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	memdel(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	memdelarr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		memdel(& arr[i]);
	free(arr);
}
