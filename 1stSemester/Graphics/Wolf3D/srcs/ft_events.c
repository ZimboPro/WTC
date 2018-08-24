/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:19 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/13 13:32:32 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
 ** check for collision
*/

static void	ft_collision(t_person *p, t_map m, int dir)
{
	int		x;
	int		y;

	if (dir == 1)
	{
		y = p->y - (int)(DIST * sin(M_PI * p->angle / 180));
		x = p->x + (int)(DIST * cos(M_PI * p->angle / 180));
		if (ft_check(y, x, m))
		{
			p->y = y;
			p->x = x;
		}
	}
	else
	{
		y = p->y + (int)(DIST * sin(M_PI * p->angle / 180));
		x = p->x - (int)(DIST * cos(M_PI * p->angle / 180));
		if (ft_check(y, x, m))
		{
			p->y = y;
			p->x = x;
		}
	}
}

/*
 ** checks see if key pressed is one wanted and sends further intstructions if
 ** true such as change angle or move position
*/

static void	ft_keys(t_person *p, t_map m)
{
	if (p->event.key.keysym.sym == SDLK_UP ||
			p->event.key.keysym.sym == SDLK_w)
		ft_collision(p, m, 1);
	if (p->event.key.keysym.sym == SDLK_DOWN ||
			p->event.key.keysym.sym == SDLK_s)
		ft_collision(p, m, 0);
	if (p->event.key.keysym.sym == SDLK_LEFT ||
			p->event.key.keysym.sym == SDLK_a)
		p->angle = (p->angle + ROTATE) % 360;
	if (p->event.key.keysym.sym == SDLK_RIGHT ||
			p->event.key.keysym.sym == SDLK_d)
		p->angle = (360 + (p->angle - ROTATE)) % 360;
	if (p->event.key.keysym.sym == SDLK_ESCAPE)
		p->loop = FALSE;
}

/*
 ** conditional statements in loop and rendering
*/

static void	ft_event_loop(t_person *p, t_map m)
{
	if (p->event.type == SDL_QUIT)
		p->loop = FALSE;
	else if (p->event.type == SDL_KEYDOWN)
		ft_keys(p, m);
}

/*
 ** to control events and event loop
*/

int			ft_events(SDL_Window *win, t_map m)
{
	t_person		p;
	SDL_Renderer	*ren;

	p.loop = TRUE;
	p.x = STRT_X;
	p.y = STRT_Y;
	p.angle = STRT_ANG;
	p.r = (t_ray *)malloc(sizeof(t_ray *));
	ren = SDL_CreateRenderer(win, -1, 0);
	while (p.loop)
	{
		while (SDL_PollEvent(&p.event))
			ft_event_loop(&p, m);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		SDL_RenderClear(ren);
		ft_ray_cast(&p, m, ren);
		SDL_RenderPresent(ren);
	}
	free(p.r);
	SDL_DestroyWindow(win);
	return (0);
}
