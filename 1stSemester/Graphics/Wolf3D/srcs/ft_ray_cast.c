/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:22:54 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/18 08:53:04 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "wolf.h"
#include "libft.h"
#include <math.h>

/*
 ** check the horizontal intersections
*/

static void	ft_hori(t_person *p)
{
	double	an;

	an = tan(M_PI * p->r->r_ang / 180);
	if (p->r->r_ang > 0 && p->r->r_ang <= 180)
	{
		p->r->ya = -64;
		p->r->y_new = (int)((p->y >> 6) * 64 - 1);
		p->r->xa = 64 / an;
	}
	else
	{
		p->r->ya = 64;
		p->r->y_new = (int)((p->y >> 6) * 64 + 64);
		p->r->xa = -64 / an;
	}
	p->r->x_new = p->x + (p->y - p->r->y_new) / an;
}

/*
 ** check vetical intersections
*/

static void	ft_verti(t_person *p)
{
	double	an;

	an = tan(M_PI * p->r->r_ang / 180);
	if (p->r->r_ang > 90 && p->r->r_ang <= 270)
	{
		p->r->xa = -64;
		p->r->x_new = (int)((p->x >> 6) * 64 - 1);
		p->r->ya = 64 * an;
	}
	else
	{
		p->r->xa = 64;
		p->r->x_new = (int)((p->x >> 6) * 64 + 64);
		p->r->ya = -64 * an;
	}
	p->r->y_new = p->y + (p->x - p->r->x_new) * an;
}

/*
 ** taking the data and converting it into distance to determine which to
 ** raycast
*/

static void	ft_convert(t_person *p)
{
	if (ft_dist(p->r->xh, p->r->yh, p) >= ft_dist(p->r->xv, p->r->yv, p))
	{
		p->r->slice_dist = ft_dist(p->r->xv, p->r->yv, p);
		p->r->ya = p->r->yv;
		p->r->xa = p->r->xv;
	}
	else
	{
		p->r->slice_dist = ft_dist(p->r->xh, p->r->yh, p);
		p->r->ya = p->r->yh;
		p->r->xa = p->r->xh;
	}
}

/*
 ** start and the control the rary cast steps
*/

static void	ft_cast(t_person *p, t_map m)
{
	if (p->r->r_ang < 0)
		p->r->r_ang = 360 + p->r->r_ang;
	ft_hori(p);
	while (p->r->y_new >= 0 && p->r->y_new < (m.y << 6) &&
		p->r->x_new >= 0 && p->r->x_new < (m.x << 6) &&
		ft_check(p->r->y_new, p->r->x_new, m))
	{
		p->r->x_new = p->r->x_new + p->r->xa;
		p->r->y_new = p->r->y_new + p->r->ya;
	}
	p->r->xh = p->r->x_new;
	p->r->yh = p->r->y_new;
	ft_verti(p);
	while (p->r->y_new >= 0 && p->r->y_new < (m.y << 6) &&
		p->r->x_new >= 0 && p->r->x_new < (m.x << 6) &&
		ft_check(p->r->y_new, p->r->x_new, m))
	{
		p->r->x_new = p->r->x_new + p->r->xa;
		p->r->y_new = p->r->y_new + p->r->ya;
	}
	p->r->xv = p->r->x_new;
	p->r->yv = p->r->y_new;
}

/*
 ** go through every column to ray cast
*/

void		ft_ray_cast(t_person *p, t_map m, SDL_Renderer *ren)
{
	int		i;

	i = 0;
	while (i < 320)
	{
		p->r->r_ang = (p->angle + 30 - (int)((i + 1) * ANGCOL)) % 360;
		ft_cast(p, m);
		ft_convert(p);
		ft_draw(i, p, ren, m);
		i++;
	}
}
