/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:29:18 by syoung            #+#    #+#             */
/*   Updated: 2017/09/19 11:29:23 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
 ** handles events and commands
*/

static void		mouse_click(t_obj *obj, int *draw, SDL_Event event)
{
	int x;
	int y;

	x = event.motion.x;
	y = event.motion.y;
	if (x >= 20 && y >= 20 && x <= 70 && y <= 70)
		update_pos(obj, draw, 0);
	else if (x >= 20 && y >= 90 && x <= 70 && y <= 115)
		update_pos(obj, draw, 1);
}

void			ft_evn(int *loop, t_obj *obj, int *draw)
{
	SDL_Event	event;
	int			i;

	if ((i = SDL_PollEvent(&event)))
	{
		if (i == 1)
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_click(obj, draw, event);
			else
				ft_eventloop(event, loop, obj, draw);
		}
	}
}

/*
 ** handles events and commands and if it is cartoon mode or normal mode
*/

static int		ft_events(SDL_Window *win, t_obj *obj)
{
	SDL_Renderer	*ren;
	int				loop;
	int				draw;

	ren = SDL_CreateRenderer(win, -1, 0);
	loop = 1;
	draw = 0;
	while (loop)
	{
		if (draw == 0)
		{
			if (obj->camera.mode == 0)
				ft_draw(obj, ren);
			else
				cartoon_draw(obj, ren);
			draw = 1;
		}
		ft_evn(&loop, obj, &draw);
	}
	SDL_DestroyRenderer(ren);
	return (0);
}

/*
 ** the ray trace sequence
*/

static void		raytrace(t_obj *obj)
{
	SDL_Window	*win;

	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			obj->camera.width, obj->camera.height, 0);
	while (ft_events(win, obj))
		;
	SDL_DestroyWindow(win);
}

/*
 ** the main sequence of events
*/

void			sequence(char *str)
{
	char	**s;
	t_obj	obj;

	s = ft_read(str);
	if (s != NULL)
	{
		if (map_check(s) == 1)
		{
			obj = objects(s);
			obj_assign(&obj, s);
			ft_strarrdel(s);
			raytrace(&obj);
			free(obj.objects);
			obj.objects = NULL;
			free(obj.lights);
			obj.lights = NULL;
		}
	}
}
