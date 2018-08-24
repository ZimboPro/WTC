/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:48:55 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/22 08:47:57 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <string.h>

int		get_offset(t_src_line *lines, char *line)
{
	int		n;

	n = 0;
	while (lines[n].label != NULL || lines[n].opcode != 0)
	{
		while (lines[n].label == NULL)
		{
			if (lines[n].num < 0)
				return (-1);
			n++;
		}
		if (lines[n].label != NULL &&
				ft_strlen(lines[n].label) - 1 == ft_strlen(line + 2))
		{
			if (ft_strncmp(lines[n].label, line + 2, ft_strlen(line + 2)) == 0)
			{
				return (n);
			}
		}
		n++;
	}
	return (-1);
}

int		check_idx(int op)
{
	int i;

	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (g_op_tab[i].opcode == op)
			return (g_op_tab[i].has_idx);
		i++;
	}
	return (-1);
}

void	write_bytes(int fd, t_src_line *lines)
{
	t_norm	n;

	n.i = 0;
	n.j = 0;
	while (lines[n.i].label != NULL || lines[n.i].opcode != 0)
	{
		if (lines[n.i].opcode != 0)
		{
			n.j = 0;
			write_opcode_and_acb(lines[n.i], fd);
			while (lines[n.i].params[n.j] != NULL)
			{
				if (lines[n.i].params[n.j][0] == 'r')
					write_register(lines[n.i].params[n.j], fd);
				else if (ft_strchr(lines[n.i].params[n.j], LABEL_CHAR) != NULL)
					write_label_adrs(lines, lines[n.i].params[n.j], fd, n.i);
				else if (lines[n.i].params[n.j][0] == DIRECT_CHAR)
					write_direct(lines[n.i], fd, n.j);
				else if (ft_isnumber(lines[n.i].params[n.j]))
					write_indirect(lines[n.i].params[n.j], fd);
				n.j++;
			}
		}
		n.i++;
	}
}
