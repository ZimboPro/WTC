/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:47:52 by prussell          #+#    #+#             */
/*   Updated: 2017/08/11 12:08:14 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixdel(void **grid)
{
	int i;

	i = 0;
	if (grid != NULL)
	{
		while (grid[i])
		{
			free(grid[i]);
			grid[i] = NULL;
			i++;
		}
		grid = NULL;
	}
}
