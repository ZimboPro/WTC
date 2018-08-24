/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:43:53 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/06 07:30:38 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		**ft_intarrnew(int row, int col)
{
	int		**arr;
	int		i;

	i = 0;
	arr = (int **)malloc(sizeof(int **) * row);
	if (arr == NULL)
		return (NULL);
	while (i < row)
	{
		arr[i] = (int *)malloc(sizeof(int *) * col);
		if (arr[i] == NULL)
			return (NULL);
		i++;
	}
	return (arr);
}
