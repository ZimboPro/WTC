/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:43:12 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 13:21:43 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
 ** finds last valid point if player = 1
*/

static void	ft_last_valid(t_game *b, t_place *pos)
{
	int		chk;

	chk = 0;
	pos->y = b->g_r - 1;
	while (pos->y >= 0)
	{
		pos->x = b->g_c - 1;
		while (pos->x >= 0)
		{
			if (b->grid[pos->y][pos->x] == 1)
			{
				chk = 1;
				break ;
			}
			pos->x = pos->x - 1;
		}
		if (chk == 1)
			break ;
		pos->y = pos->y - 1;
	}
}

/*
 ** gets the most left, most right, most top and most bottom piece that was
 ** previously placed
*/

static void	ft_player_place(t_game *b, t_place *pos)
{
	int		r;
	int		c;

	r = 0;
	while (r < b->g_r)
	{
		c = 0;
		while (c < b->g_c)
		{
			if (b->grid[r][c] == b->player)
			{
				if (c < pos->pl)
					pos->pl = c;
				if (c > pos->pr)
					pos->pr = c;
				if (r < pos->pt)
					pos->pt = r;
				if (r > pos->pb)
					pos->pb = r;
			}
			c++;
		}
		r++;
	}
}

/*
 ** finds the most valid place to the left, right, top and bottom
*/

static void	ft_valid_place(t_game *b, t_place *pos)
{
	int		r;
	int		c;

	r = 0;
	while (r < b->g_r)
	{
		c = 0;
		while (c < b->g_c)
		{
			if (b->grid[r][c] == 1)
			{
				if (c < pos->vl)
					pos->vl = c;
				if (c > pos->vr)
					pos->vr = c;
				if (r < pos->vt)
					pos->vt = r;
				if (r > pos->vb)
					pos->vb = r;
			}
			c++;
		}
		r++;
	}
}

/*
 ** finds the first valid move from the top left corner so that player 2 can
 ** overwhelm and work towards the opponent
*/

static void	ft_first_valid(t_game *b, t_place *pos)
{
	int		chk;

	chk = 0;
	pos->y = 0;
	while (pos->y < b->g_r)
	{
		pos->x = 0;
		while (pos->x < b->g_c)
		{
			if (b->grid[pos->y][pos->x] == 1)
			{
				chk = 1;
				break ;
			}
			pos->x = pos->x + 1;
		}
		if (chk == 1)
			break ;
		pos->y = pos->y + 1;
	}
}

/*
 ** initailises the values and works through the sequence
*/

void		ft_place(t_game *b)
{
	t_place	pos;

	ft_init(b, &pos);
	ft_valid_place(b, &pos);
	ft_player_place(b, &pos);
	if (ft_x_plane(b, &pos) == 1)
		ft_output(b, pos.x, pos.y);
	else if (ft_y_plane(b, &pos) == 1)
		ft_output(b, pos.x, pos.y);
	else if (b->player == 79)
	{
		ft_last_valid(b, &pos);
		ft_output(b, pos.x, pos.y);
	}
	else
	{
		ft_first_valid(b, &pos);
		ft_output(b, pos.x, pos.y);
	}
}
