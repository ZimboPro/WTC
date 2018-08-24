/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:25:20 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/30 15:35:14 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int		**ft_line_to_num(char **src, int *y, int *x, int **pts)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	while (j < *y)
	{
		temp = ft_strsplit(src[j], 32);
		i = 0;
		while (temp[i] != NULL)
			i++;
		if ((pts[j] = (int *)malloc(sizeof(int *) * i)) == NULL)
			return (NULL);
		i = 0;
		while (temp[i] != NULL)
		{
			pts[j][i] = ft_atoi(temp[i]);
			ft_strdel(&temp[i]);
			i++;
		}
		j++;
	}
	*x = i;
	return (pts);
}

int				**ft_read(char *str, int **pts, int *y, int *x)
{
	char	**file;
	char	*temp;
	int		i;
	int		fd;

	i = 0;
	fd = ft_open(str);
	file = (char **)malloc(sizeof(char **) * (*y + 1));
	if (file == NULL)
		return (NULL);
	file[*y] = NULL;
	while (get_next_line(fd, &temp) > 0)
	{
		file[i] = temp;
		i++;
	}
	close(fd);
	pts = ft_line_to_num(file, y, x, pts);
	i = 0;
	while (i < *y)
	{
		ft_strdel(&file[i]);
		i++;
	}
	return (pts);
}
