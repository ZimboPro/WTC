/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 07:51:05 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/13 11:15:37 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <SDL2/SDL.h>

/*
 ** calculate the distance
*/

int			ft_dist(int x, int y, t_person *p)
{
	int		d;
	double	xp;
	double	yp;

	xp = pow((p->x - x), 2);
	yp = pow((p->y - y), 2);
	d = (int)sqrt(xp + yp);
	return (d);
}

/*
 ** opens the map tp be read
*/

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

/*
 ** counts the amount of lines in the map so that the correct amount of memory
 ** can be allocated later
*/

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

/*
 ** the main
*/

int			main(int ac, char *av[])
{
	t_map		m;
	SDL_Window	*win;
	int			i;

	if (ac != 2)
	{
		ft_putendl("Usage: ./wolf map");
		return (1);
	}
	m.y = ft_line_count(av[1]);
	if ((m.pts = (int **)malloc(sizeof(int **) * (m.y + 2))) == NULL)
		return (1);
	m.pts = ft_read_map(av[1], m.pts, &m.y, &m.x);
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Wolf 3D", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 320, 200, 0);
	while (ft_events(win, m))
		;
	i = 0;
	while (i < m.y)
	{
		free(m.pts[i]);
		i++;
	}
	return (0);
}
