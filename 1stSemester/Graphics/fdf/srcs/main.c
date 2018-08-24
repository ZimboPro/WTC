/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:58:49 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/30 15:37:24 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ext(int keycode, void *m)
{
	t_p	*temp;

	temp = (t_p *)m;
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(temp->mlx, temp->win);
		exit(0);
	}
	return (keycode);
}

int			ft_open(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error opening the file: ");
		ft_putendl(str);
		exit(0);
	}
	return (fd);
}

static int	ft_line_count(char *str)
{
	char	temp[1];
	int		i;
	int		fd;
	int		ch;

	i = 0;
	fd = ft_open(str);
	while (read(fd, temp, 1))
	{
		ch = 0;
		if (temp[0] == '\n')
		{
			i++;
			ch = 1;
		}
	}
	if (ch == 0)
		i++;
	return (i);
}

static void	pts_free(int **pts, t_p m)
{
	int	i;

	i = 0;
	while (i < m.y)
	{
		free(pts[i]);
		i++;
	}
	free(pts);
}

int			main(int ac, char **av)
{
	t_p			m;
	static int	**pts;

	if (ac != 2)
	{
		ft_putendl("No or too many files as parameters");
		return (1);
	}
	m.y = ft_line_count(av[1]);
	if ((pts = (int **)malloc((sizeof(int **)) * m.y)) == NULL)
		return (-1);
	pts = ft_read(av[1], pts, &m.y, &m.x);
	ft_draw(pts, &m, av[1]);
	pts_free(pts, m);
	mlx_key_hook(m.win, ext, (void *)&m);
	mlx_loop(m.mlx);
	return (0);
}
