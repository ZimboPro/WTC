/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:28:05 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/30 15:39:07 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		ft_lines(t_p *m)
{
	int		g;
	int		c;
	int		x;
	int		y;
	int		color;

	color = 0xFFFFFF;
	g = (m->y1 - m->y2) / (m->x1 - m->x2);
	c = m->y1 - g * m->x1;
	if (m->x1 > m->x2)
		x = m->x2;
	else
		x = m->x1;
	while (x < m->x1 || x < m->x2)
	{
		y = g * x + c;
		mlx_pixel_put(m->mlx, m->win, x, y, color);
		x++;
	}
}

static int		ft_max(int **pts, int x, int y)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (pts[i][j] > max)
				max = pts[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

static void		ft_pos(int **pts, t_p *m, t_count c)
{
	int	d;

	d = 10 * sin(M_PI / 4);
	if (c.i + 1 < m->x && c.j < m->y)
	{
		m->x1 = m->x0 - c.j * d + c.i * d;
		m->y1 = m->y0 + c.j * d + c.i * d - pts[c.j][c.i];
		m->x2 = m->x0 - (c.j) * d + (c.i + 1) * d;
		m->y2 = m->y0 + (c.j) * d + (c.i + 1) * d - pts[c.j][c.i + 1];
		ft_lines(m);
	}
	if (c.i < m->x && c.j + 1 < m->y)
	{
		m->x1 = m->x0 - c.j * d + c.i * d;
		m->y1 = m->y0 + c.j * d + c.i * d - pts[c.j][c.i];
		m->x2 = m->x0 - (c.j + 1) * d + (c.i) * d;
		m->y2 = m->y0 + (c.j + 1) * d + (c.i) * d - pts[c.j + 1][c.i];
		ft_lines(m);
	}
}

static void		ft_pts(int **pts, t_p *m, t_count c)
{
	c.i = 0;
	while (c.i < m->x)
	{
		c.j = 0;
		while (c.j < m->y)
		{
			ft_pos(pts, m, c);
			c.j = c.j + 1;
		}
		c.i = c.i + 1;
	}
}

void			ft_draw(int **pts, t_p *m, char *s)
{
	int		xs;
	int		ys;
	t_count	c;

	m->x0 = (int)sqrt(pow(m->x, 2) + pow(m->y, 2)) * 10;
	m->y0 = ft_max(pts, m->x, m->y) * 10;
	m->mlx = mlx_init();
	xs = (2 * m->x0);
	ys = (2 * m->x0 + m->y0);
	m->win = mlx_new_window(m->mlx, xs, ys, s);
	c.i = 0;
	c.j = 0;
	ft_pts(pts, m, c);
}
