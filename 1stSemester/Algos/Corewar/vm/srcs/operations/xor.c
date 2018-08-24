/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 22:29:23 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 22:33:29 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	exec_op(t_process *p, t_op_var v)
{
	if (v.t[3] == T_REG && valid_reg(v.p[3]) == 1)
	{
		p->pc = (p->pc + v.t[1] + v.t[2] + v.t[3] + 1) % MEM_SIZE;
		write_to_reg(p->reg[v.p[3] - 1], v.p[1] ^ v.p[2]);
		p->carry = 1;
	}
	else
	{
		p->pc = (p->pc + v.t[1] + v.t[2] + v.t[3]) % MEM_SIZE;
		p->carry = 0;
		return (0);
	}
	return (1);
}

int			op_xor(t_process *p, t_core *arena)
{
	int			i;
	t_op_var	v;

	v.acb = arena[(p->pc + 1) % MEM_SIZE].raw;
	init_var(&v);
	p->pc = (p->pc + 1) % MEM_SIZE;
	i = 1;
	v.p[1] = data_var((p->pc + 1) % MEM_SIZE, arena, v.t[1]);
	v.p[2] = data_var((p->pc + v.t[1] + 1) % MEM_SIZE, arena, v.t[2]);
	v.p[3] = data_var((p->pc + v.t[1] + v.t[2] + 1) % MEM_SIZE, arena, v.t[3]);
	while (i <= 2)
	{
		if ((v.t[i] == T_REG && valid_reg(v.p[i]) == 1) || v.t[i] == DIR_SIZE ||
					v.t[i] == IND_SIZE)
			i++;
		else
			break ;
	}
	if (i == 3)
		return (exec_op(p, v));
	p->pc = (p->pc + v.t[1] + v.t[2] + v.t[3] + 1) % MEM_SIZE;
	p->carry = 0;
	return (0);
}
