/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_y_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:41:35 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 08:49:53 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 ** finds the first valid move from the right
*/

static int	ft_f_r(t_game *b, t_place *pos, int row)
{
	int		c;

	c = b->g_c - 1;
	while (c >= 0)
	{
		if (b->grid[row][c] == 1)
		{
			pos->y = row;
			pos->x = c;
			return (1);
		}
		c--;
	}
	return (0);
}

/*
 ** finds the first valid move the bottom
*/

static int	ft_bottom(t_game *b, t_place *pos)
{
	int		c;

	if (b->player == 79)
	{
		c = 0;
		while (c < b->g_c)
		{
			if (b->grid[pos->vb][c] == 1)
			{
				pos->y = pos->vb;
				pos->x = c;
				return (1);
			}
			c++;
		}
	}
	else
	{
		if (ft_f_r(b, pos, pos->vb) == 1)
			return (1);
	}
	return (0);
}

/*
 ** finds the first valid move from the top
*/

static int	ft_top(t_game *b, t_place *pos)
{
	int		c;

	if (b->player == 79)
	{
		c = 0;
		while (c < b->g_c)
		{
			if (b->grid[pos->vt][c] == 1)
			{
				pos->y = pos->vt;
				pos->x = c;
				return (1);
			}
			c++;
		}
	}
	else
	{
		if (ft_f_r(b, pos, pos->vt) == 1)
			return (1);
	}
	return (0);
}

/*
 ** determines what to do if the distance from the most top and bottom point
 ** to the edge is the same according to player number
*/

static int	ft_equal(t_game *b, t_place *pos)
{
	if (b->player == 79)
	{
		if (ft_bottom(b, pos) == 1)
			return (1);
	}
	else
	{
		if (ft_top(b, pos) == 1)
			return (1);
	}
	return (0);
}

/*
 ** determines what to do according to the distance of the most top and bottom
 ** piece from the edge
*/

int			ft_y_plane(t_game *b, t_place *pos)
{
	if (pos->pt == 0 && pos->pb == b->g_r - 1)
		return (0);
	if (pos->pt < b->g_r - pos->pb - 1)
	{
		if (ft_bottom(b, pos) == 1)
			return (1);
	}
	else if (pos->pt > b->g_r - pos->pb - 1)
	{
		if (ft_top(b, pos) == 1)
			return (1);
	}
	else if (pos->pt == b->g_r - pos->pb - 1)
	{
		if (ft_equal(b, pos) == 1)
			return (1);
	}
	return (0);
}
