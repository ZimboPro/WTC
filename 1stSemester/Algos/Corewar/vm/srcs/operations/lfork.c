/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:50:17 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 17:54:06 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lfork(t_process *p, t_core *arena)
{
	int			p1;
	t_process	*new;

	p1 = data_var((p->pc + 1) % MEM_SIZE, arena, IND_SIZE);
	if ((new = new_proc(p, (p->pc + p1) % MEM_SIZE)))
		append_proc(p, new);
	else
	{
		p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
		p->carry = 0;
		return (0);
	}
	p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
	p->carry = 1;
	return (1);
}
