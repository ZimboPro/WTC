/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:22:01 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 08:47:46 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 ** finds the valid move with the row starting from the right and col fixed
*/

static int	ft_f_b(t_game *b, t_place *pos, int col)
{
	int		r;

	r = b->g_r - 1;
	while (r >= 0)
	{
		if (b->grid[r][col] == 1)
		{
			pos->y = r;
			pos->x = col;
			return (1);
		}
		r--;
	}
	return (0);
}

/*
 ** finds the most right valid move
*/

static int	ft_right(t_game *b, t_place *pos)
{
	int		r;

	if (b->player == 79)
	{
		r = 0;
		while (r < b->g_r)
		{
			if (b->grid[r][pos->vr] == 1)
			{
				pos->y = r;
				pos->x = pos->vr;
				return (1);
			}
			r++;
		}
	}
	else
	{
		if (ft_f_b(b, pos, pos->vr) == 1)
			return (1);
	}
	return (0);
}

/*
 ** finds the most left valid move
*/

static int	ft_left(t_game *b, t_place *pos)
{
	int		r;

	if (b->player == 79)
	{
		r = 0;
		while (r < b->g_r)
		{
			if (b->grid[r][pos->vl] == 1)
			{
				pos->y = r;
				pos->x = pos->vl;
				return (1);
			}
			r++;
		}
	}
	else
	{
		if (ft_f_b(b, pos, pos->vl) == 1)
			return (1);
	}
	return (0);
}

/*
 ** determines what action to take if the distance the most right and left
 ** piece from the edge is the same
*/

static int	ft_equal(t_game *b, t_place *pos)
{
	if (b->player == 79)
	{
		if (ft_right(b, pos) == 1)
			return (1);
	}
	else
	{
		if (ft_left(b, pos) == 1)
			return (1);
	}
	return (0);
}

/*
 ** checks the distance with the most right and left piece from the edge,
 ** compares them and then determines what statergy to do
*/

int			ft_x_plane(t_game *b, t_place *pos)
{
	if (pos->pl == 0 && pos->pr == b->g_c - 1)
		return (0);
	if (pos->pl < b->g_c - pos->pr - 1)
	{
		if (ft_right(b, pos) == 1)
			return (1);
	}
	else if (pos->pl > b->g_c - pos->pr - 1)
	{
		if (ft_left(b, pos) == 1)
			return (1);
	}
	else if (pos->pl == b->g_c - pos->pr - 1)
	{
		if (ft_equal(b, pos) == 1)
			return (1);
	}
	return (0);
}
