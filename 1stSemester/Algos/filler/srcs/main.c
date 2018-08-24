/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:42:24 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 12:42:13 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

/*
 ** giving the output coordinates
*/

void		ft_output(t_game *b, int x, int y)
{
	ft_arrdel(b->grid, b->g_r);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd('\n', 1);
}

/*
 ** sequence of functions to make it easier to control and loop
*/

int			ft_sequence(t_game *b)
{
	ft_plateau_size(b);
	ft_grid_convert(b);
	ft_piece_size(b);
	ft_piece_convert(b);
	ft_valid(b);
	if (b->v > 0)
	{
		ft_place(b);
		return (1);
	}
	return (0);
}

/*
 ** initialises the values to find the most valid points
*/

void		ft_init(t_game *b, t_place *pos)
{
	pos->vl = b->g_c;
	pos->vr = 0;
	pos->vt = b->g_r;
	pos->vb = 0;
	pos->pl = b->g_c;
	pos->pr = 0;
	pos->pt = b->g_r;
	pos->pb = 0;
}

/*
 ** get the player number, if 1, player = 79, if 2, player = 88
*/

static void	ft_player(t_game *b)
{
	char	*temp;

	get_next_line(0, &temp);
	if (temp[10] == '1')
	{
		b->player = 79;
		b->opp = 88;
	}
	else if (temp[10] == '2')
	{
		b->player = 88;
		b->opp = 79;
	}
	ft_strdel(&temp);
}

/*
 ** the main
*/

int			main(void)
{
	t_game	b;

	ft_player(&b);
	while (ft_sequence(&b))
		;
	return (0);
}
