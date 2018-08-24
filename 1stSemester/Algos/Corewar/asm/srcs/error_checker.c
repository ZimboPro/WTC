/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:06:00 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/30 11:31:45 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_params(t_src_line line)
{
	int	n;
	int	p;

	n = 0;
	while (g_op_tab[n].opcode != line.opcode)
		n++;
	p = 0;
	while (p < g_op_tab[n].nb_params && line.params[p] != NULL)
	{
		if (line.params[p][0] == 'r')
		{
			if (check_registers(line, p) == 1)
				return (1);
		}
		if ((g_op_tab[n].param_types[p] & line.param_type[p])
				!= line.param_type[p])
		{
			print_error("Parameter is wrong", line.num);
			return (1);
		}
		p++;
	}
	return (0);
}

int		check_nb_params(t_src_line line)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (g_op_tab[n].opcode != line.opcode)
		n++;
	if (line.params[g_op_tab[n].nb_params] != NULL)
	{
		print_error("Too many parameters", line.num);
		return (1);
	}
	else
	{
		while (line.params[i] != NULL)
			i++;
		if (i < g_op_tab[n].nb_params)
		{
			print_error("Too little parameters", line.num);
			return (1);
		}
	}
	return (0);
}

int		check_labels(t_src_line *lines)
{
	int	i;
	int	p;

	i = 0;
	while (lines[i].label != NULL || lines[i].opcode != 0)
	{
		p = 0;
		if (lines[i].opcode != 0)
			while (lines[i].params[p] != NULL)
			{
				if (ft_strchr(lines[i].params[p], LABEL_CHAR) != NULL)
				{
					if (get_offset(lines, lines[i].params[p]) == -1)
					{
						print_error("Label does not exist", lines[i].num);
						return (1);
					}
				}
				p++;
			}
		i++;
	}
	return (0);
}

int		check_size(t_src_line *lines)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (lines[i].num >= 0)
	{
		n += lines[i].bytes;
		i++;
	}
	if (n > CHAMP_MAX_SIZE)
		return (1);
	return (0);
}

int		check_errors(t_src_line *lines)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (lines[i].label != NULL || lines[i].opcode != 0)
	{
		if (lines[i].opcode != 0)
		{
			error = (error | check_params(lines[i]));
			error = (error | check_nb_params(lines[i]));
		}
		i++;
	}
	error = (error | check_size(lines));
	error = (error | check_labels(lines));
	return (error);
}
