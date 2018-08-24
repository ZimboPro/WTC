/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:14:43 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/22 08:45:03 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_bytes(t_src_line *lines, int i, int n, int p)
{
	if (ft_strchr(lines[i].params[p], DIRECT_CHAR) &&
			g_op_tab[n].has_idx == 0)
		lines[i].bytes += DIR_SIZE;
	else if (ft_strchr(lines[i].params[p], DIRECT_CHAR)
			&& g_op_tab[n].has_idx == 1)
		lines[i].bytes += IND_SIZE;
	else if (lines[i].params[p][0] == 'r')
		lines[i].bytes += REG_SIZE;
	else if (ft_isnumber(lines[i].params[p]))
		lines[i].bytes += IND_SIZE;
}

int		get_bytes(t_src_line *lines)
{
	int	i;
	int	n;
	int	p;

	i = 0;
	while (lines[i].num >= 0)
	{
		n = 0;
		if (lines[i].opcode != 0)
		{
			while (n < 16 && g_op_tab[n].opcode != lines[i].opcode)
				n++;
			p = 0;
			if (lines[i].acb != 0)
				lines[i].bytes += 1;
			lines[i].bytes += 1;
			while (p < g_op_tab[n].nb_params && lines[i].params[p])
			{
				add_bytes(lines, i, n, p);
				p++;
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
