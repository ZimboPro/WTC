/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:04 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/13 12:33:04 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <SDL2/SDL.h>

/*
 ** checks to see if on edge of wall, first is above and diagnol, then below
 ** and diagnol, then next to position and it self
*/

int			ft_check(int r, int c, t_map m)
{
	if (m.pts[r >> 6][c >> 6] != 0)
		return (0);
	return (1);
}

/*
 ** check wall color
*/

static void	ft_color(SDL_Renderer *ren, t_map m, t_person *p)
{
	if (m.pts[p->r->ya >> 6][p->r->xa >> 6] == 1)
		SDL_SetRenderDrawColor(ren, p->d, p->d, p->d, 0);
	else if (m.pts[p->r->ya >> 6][p->r->xa >> 6] == 2)
		SDL_SetRenderDrawColor(ren, 0, p->d, p->d, 0);
	else if (m.pts[p->r->ya >> 6][p->r->xa >> 6] == 3)
		SDL_SetRenderDrawColor(ren, 0, 0, p->d, 0);
	else if (m.pts[p->r->ya >> 6][p->r->xa >> 6] == 4)
		SDL_SetRenderDrawColor(ren, p->d, p->d, 0, 0);
	else if (m.pts[p->r->ya >> 6][p->r->xa >> 6] == 5)
		SDL_SetRenderDrawColor(ren, p->d, 0, 0, 0);
}

/*
 ** draw a col
*/

static void	ft_rect(int i, t_person *p, SDL_Renderer *ren, t_map m)
{
	int		y1;
	int		y2;
	int		y;

	y1 = 100 - p->r->slice_hght / 2;
	y2 = 100 + p->r->slice_hght / 2;
	y = 0;
	while (y < 200)
	{
		if (y < y1 && y < 100)
			SDL_SetRenderDrawColor(ren, 125 - y, 125 - y, 125 - y, 0);
		else if (y >= y1 && y <= y2)
			ft_color(ren, m, p);
		else
			SDL_SetRenderDrawColor(ren, y - 75, y - 40, y - 75, 0);
		SDL_RenderDrawPoint(ren, i, y);
		y++;
	}
}

/*
 ** find the actual height
*/

void		ft_draw(int i, t_person *p, SDL_Renderer *ren, t_map m)
{
	p->r->slice_dist = (p->r->slice_dist * cos(((30 - i * ANGCOL)
				/ 180) * M_PI));
	p->d = CC - CG * p->r->slice_dist;
	if (p->d < 0)
		p->d = 0;
	p->r->slice_hght = (CONVERT / p->r->slice_dist);
	if (p->r->slice_hght > 200)
		p->r->slice_hght = 200;
	ft_rect(i, p, ren, m);
}
