/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 07:51:25 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/18 15:18:01 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <SDL2/SDL.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

# define DIST 10
# define ROTATE 1

# define STRT_ANG 0
# define STRT_Y 100
# define STRT_X 100

/*
 ** Convert = 64 * 277 ANGOL = 60 / 320
*/

# define CONVERT 17728
# define ANGCOL 0.1875
# define CG 0.5
# define CC 255

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_ray
{
	int			ya;
	int			xa;
	int			x_new;
	int			y_new;
	double		r_ang;
	int			slice_dist;
	int			slice_hght;
	int			yh;
	int			xh;
	int			yv;
	int			xv;
}				t_ray;

typedef struct	s_map
{
	int			y;
	int			x;
	int			**pts;
}				t_map;

typedef struct	s_person
{
	int			x;
	int			y;
	int			angle;
	SDL_Event	event;
	t_bool		loop;
	int			d;
	t_ray		*r;
}				t_person;

int				**ft_read_map(char *str, int **pts, int *y, int *x);
int				ft_open(char *str);
void			ft_ray_cast(t_person *p, t_map m, SDL_Renderer *ren);
void			ft_draw(int i, t_person *p, SDL_Renderer *ren, t_map m);
int				ft_events(SDL_Window *win, t_map m);
int				ft_check(int r, int c, t_map m);
int				ft_dist(int x, int y, t_person *p);

#endif
