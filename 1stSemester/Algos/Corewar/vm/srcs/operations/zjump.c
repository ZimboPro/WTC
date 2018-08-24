/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:22:01 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 18:02:51 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_process *p, t_core *arena)
{
	int	p1;

	if (p->carry <= 0)
	{
		p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
		return (0);
	}
	p1 = data_var((p->pc + 1) % MEM_SIZE, arena, IND_SIZE);
	p->pc = (p->pc + (p1 % IDX_MOD)) % MEM_SIZE;
	return (1);
}
