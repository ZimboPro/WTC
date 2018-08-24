/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:41:34 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 09:29:14 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_LINES 1050

typedef struct	s_game
{
	int			player;
	int			opp;
	int			v;
	int			g_r;
	int			g_c;
	int			**grid;
	int			p_r;
	int			p_c;
	int			**piece;
}				t_game;

typedef struct	s_cnt
{
	int			pr;
	int			pc;
	int			count;
	int			ll;
	int			bl;
}				t_cnt;

typedef struct	s_place
{
	int			vl;
	int			vr;
	int			vt;
	int			vb;
	int			pl;
	int			pr;
	int			pt;
	int			pb;
	int			x;
	int			y;
}				t_place;

int				ft_sequence(t_game *b);
void			ft_plateau_size(t_game *b);
void			ft_piece_size(t_game *b);
void			ft_grid_convert(t_game *b);
void			ft_piece_convert(t_game *b);
void			ft_valid(t_game *b);
void			ft_place(t_game *b);
int				ft_x_plane(t_game *b, t_place *pos);
int				ft_y_plane(t_game *b, t_place *pos);
void			ft_output(t_game *b, int x, int y);
void			ft_init(t_game *b, t_place *pos);

#endif
