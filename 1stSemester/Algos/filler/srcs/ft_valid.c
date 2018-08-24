/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:42:58 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 09:01:20 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdio.h>

/*
 ** get the most left and most bottom point of the piece
*/

void		ft_last(t_game *b, t_cnt *c)
{
	int		r;
	int		col;

	c->ll = 0;
	c->bl = 0;
	r = 0;
	while (r < b->p_r)
	{
		col = 0;
		while (col < b->p_c)
		{
			if (b->piece[r][col] == b->player)
			{
				if (r > c->bl)
					c->bl = r;
				if (col > c->ll)
					c->ll = col;
			}
			col++;
		}
		r++;
	}
}

/*
 ** counts number of times piece overlaps with the grid for given position,
 ** if the piece at that point = player and the grid = opp 0 is returned
*/

static int	ft_count(t_game *b, int gr, int gc, t_cnt *c)
{
	int		cnt;

	cnt = 0;
	while (c->bl + gr < b->g_r && c->pr <= c->bl)
	{
		c->pc = 0;
		while (c->ll + gc < b->g_c && c->pc <= c->ll)
		{
			if (b->grid[gr + c->pr][gc + c->pc] == b->piece[c->pr][c->pc] &&
					b->piece[c->pr][c->pc] == b->player)
				cnt++;
			if (b->grid[gr + c->pr][gc + c->pc] == b->opp &&
					b->piece[c->pr][c->pc] == b->player)
				return (0);
			c->pc = c->pc + 1;
		}
		c->pr = c->pr + 1;
	}
	return (cnt);
}

/*
 ** checks to see if count = 1, if so the the same point on the grid is 1, else
 ** it is 0
*/

static void	ft_chk(t_game *b, int gr, int gc, t_cnt *c)
{
	c->pr = 0;
	c->pc = 0;
	c->count = ft_count(b, gr, gc, c);
	if (c->count == 1)
	{
		b->v = b->v + 1;
		b->grid[gr][gc] = 1;
	}
}

/*
 ** checks every point in gid to see if it is avild move or not
*/

void		ft_valid(t_game *b)
{
	int		gr;
	int		gc;
	t_cnt	c;

	c.pr = 0;
	gr = 0;
	b->v = 0;
	ft_last(b, &c);
	while (gr < b->g_r)
	{
		gc = 0;
		while (gc < b->g_c)
		{
			ft_chk(b, gr, gc, &c);
			gc++;
		}
		gr++;
	}
	ft_arrdel(b->piece, b->p_r);
}
