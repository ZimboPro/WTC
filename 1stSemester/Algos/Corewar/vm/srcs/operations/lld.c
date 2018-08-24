/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 07:26:39 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/30 17:55:35 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		op_lld(t_process *p, t_core *arena)
{
	int load_val;
	int acb;
	int	chk;

	acb = (arena[(p->pc + 1) % MEM_SIZE].raw);
	p->pc = (p->pc + 2) % MEM_SIZE;
	if (is_direct(acb, 0) == 1)
		load_val = data_var(p->pc, arena, REG_SIZE);
	else if (is_indirect(acb, 0) == 1)
		load_val = data_var((p->pc + (data_var(p->pc, arena, IND_SIZE)))
				% MEM_SIZE, arena, IND_SIZE);
	chk = (is_direct(acb, 0) == 1 || is_indirect(acb, 0) == 1) ? 1 : 0;
	p->pc = pc_counter(p->pc, acb, 0);
	if (chk == 1 && is_register(acb, 1) == 1 && valid_reg(arena[(p->pc)
				% MEM_SIZE].raw))
	{
		chk++;
		write_to_reg(p->reg[data_var(p->pc, arena, T_REG) - 1], load_val);
	}
	p->pc = pc_counter(p->pc, acb, 1);
	p->carry = (chk == 2) ? 1 : 0;
	if (chk == 2)
		return (1);
	return (0);
}
