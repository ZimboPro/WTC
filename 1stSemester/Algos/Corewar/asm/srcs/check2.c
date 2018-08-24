/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:50:47 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 11:31:50 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_registers(t_src_line line, int p)
{
	if (ft_atoi(line.params[p] + 1) > REG_NUMBER)
	{
		print_error("Register number too big", line.num);
		return (1);
	}
	else if (ft_atoi(line.params[p] + 1) < 0)
	{
		print_error("Register number must be positive", line.num);
		return (1);
	}
	return (0);
}

int		is_code_line(char **line)
{
	while (*line)
	{
		if (is_label_address(*line) || is_opcode(*line) ||
				is_param(*line))
			return (1);
		else if (is_comment(*line))
			return (0);
		line++;
	}
	return (0);
}

int		is_valid_fd(int fd)
{
	return (fd > 0);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
