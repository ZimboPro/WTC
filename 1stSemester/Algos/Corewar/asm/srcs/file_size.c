/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:05:00 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/21 16:31:51 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	champ_size(t_src_line *lines, t_binary *bin)
{
	int	i;

	i = 0;
	while (lines[i].label != NULL || lines[i].opcode != 0)
	{
		bin->header.prog_size += lines[i].bytes;
		i++;
	}
}
