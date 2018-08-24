/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 07:52:56 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 09:52:44 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		value_from_core(t_core *arena, int pc, int size)
{
	int		k;
	int		j;
	char	num[9];

	ft_bzero(num, 9);
	k = 0;
	j = 0;
	while (j < size)
	{
		write_char_to_hex(arena[pc].raw, num + k);
		k += 2;
		pc = (pc + 1) % MEM_SIZE;
		j++;
	}
	return (ft_htoi(num, size * 2));
}

int		write_to_core(t_core *arena, int pc, int val, int size)
{
	int		i;
	int		t;

	i = 0;
	while (i < size)
	{
		t = val >> (((size - 1) << 3) - (i << 3));
		arena[pc + i % MEM_SIZE].raw = t;
		write_char_to_hex(t, arena[pc + i].value);
		i++;
	}
	return (1);
}
