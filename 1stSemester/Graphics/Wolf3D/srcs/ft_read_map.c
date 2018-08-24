/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:22:08 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/13 11:08:03 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

/*
 ** changes the string into an int 2d array
*/

static int		**ft_line_to_num(char **src, int *y, int *x, int **pts)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	*x = 0;
	while (j < *y)
	{
		temp = ft_strsplit(src[j], 32);
		if (*x == 0)
		{
			while (temp[*x] != NULL)
				*x = *x + 1;
		}
		pts[j] = (int *)malloc(sizeof(int *) * (*x));
		i = 0;
		while (i < *x && j < *y)
		{
			pts[j][i] = ft_atoi(temp[i]);
			ft_strdel(&temp[i]);
			i++;
		}
		j++;
	}
	return (pts);
}

/*
 ** starts the process of reading the map and changing it into an array and
 ** place the border
*/

int				**ft_read_map(char *str, int **pts, int *y, int *x)
{
	char	**file;
	int		i;
	int		fd;

	i = 0;
	fd = ft_open(str);
	file = (char **)malloc(sizeof(char **) * (*y + 1));
	if (file == NULL)
		return (NULL);
	file[*y] = NULL;
	while (get_next_line(fd, &file[i]) > 0)
		i++;
	close(fd);
	pts = ft_line_to_num(file, y, x, pts);
	i = 0;
	while (i < *y)
	{
		ft_strdel(&file[i]);
		i++;
	}
	free(file);
	return (pts);
}
