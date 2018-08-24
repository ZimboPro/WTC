/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:36:57 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 17:55:58 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(t_process *p, t_core *arena)
{
	int			p1;
	t_process	*new;

	p1 = data_var((p->pc + 1) % MEM_SIZE, arena, IND_SIZE);
	if ((new = new_proc(p, (p->pc + (p1 % IDX_MOD)) % MEM_SIZE)))
		append_proc(p, new);
	else
	{
		p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
		return (0);
	}
	p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
	return (1);
}
