/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:42:44 by lde-jage          #+#    #+#             */
/*   Updated: 2017/07/08 08:57:52 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdio.h>

/*
 ** get the size of the grid or plateau
*/

void		ft_plateau_size(t_game *b)
{
	char	*temp;
	char	**split;

	while (get_next_line(0, &temp) > 0)
	{
		if (ft_strstr(temp, "Plateau") != NULL)
			break ;
		ft_strdel(&temp);
	}
	split = ft_strsplit(temp, ' ');
	ft_strdel(&temp);
	b->g_r = ft_atoi(split[1]);
	temp = ft_strdup(split[2]);
	ft_strarrdel(split);
	free(split);
	split = ft_strsplit(temp, ':');
	b->g_c = ft_atoi(split[0]);
	ft_strarrdel(split);
	free(split);
}

/*
 ** get size of the piece
*/

void		ft_piece_size(t_game *b)
{
	char	*temp;
	char	**split;

	while (get_next_line(0, &temp) > 0)
	{
		if (ft_strstr(temp, "Piece") != NULL)
			break ;
		ft_strdel(&temp);
	}
	split = ft_strsplit(temp, ' ');
	ft_strdel(&temp);
	b->p_r = ft_atoi(split[1]);
	temp = ft_strdup(split[2]);
	ft_strarrdel(split);
	free(split);
	split = ft_strsplit(temp, ':');
	b->p_c = ft_atoi(split[0]);
	ft_strarrdel(split);
	free(split);
}

/*
 ** convert the board, x or X = 88, o or O = 79,  '.' = 0
*/

static void	ft_g_c(t_game *b, char **str)
{
	int		r;
	int		c;

	r = 0;
	while (r < b->g_r)
	{
		c = 0;
		while (c < b->g_c)
		{
			if (str[r][c + 4] == 'x' || str[r][c + 4] == 'X')
				b->grid[r][c] = 88;
			else if (str[r][c + 4] == 'o' || str[r][c + 4] == 'O')
				b->grid[r][c] = 79;
			else
				b->grid[r][c] = 0;
			c++;
		}
		ft_strdel(&str[r]);
		r++;
	}
}

/*
 ** convert the board to a 2d int array
*/

void		ft_grid_convert(t_game *b)
{
	int		r;
	int		chk;
	char	*str[MAX_LINES];

	b->grid = ft_intarrnew(b->g_r, b->g_c);
	r = 0;
	chk = 0;
	while (r < b->g_r && get_next_line(0, &str[r]) > 0)
	{
		if (ft_strstr(str[r], "000") != NULL)
			chk = 1;
		if (chk == 1)
			r++;
		else
			ft_strdel(&str[r]);
	}
	ft_g_c(b, str);
}

/*
 ** convert the piece to a 2d int array, '*' = player number (79 or 88), '.' = 0
*/

void		ft_piece_convert(t_game *b)
{
	int		r;
	int		c;
	char	*str[MAX_LINES];

	b->piece = ft_intarrnew(b->p_r, b->p_c);
	r = 0;
	while (r < b->p_r && get_next_line(0, &str[r]) > 0)
		r++;
	r = 0;
	while (r < b->p_r)
	{
		c = 0;
		while (c < b->p_c)
		{
			if (str[r][c] == '*')
				b->piece[r][c] = b->player;
			c++;
		}
		ft_strdel(&str[r]);
		r++;
	}
}
