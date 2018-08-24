/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:16:43 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 11:27:56 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		check_param_type(t_op_var *v)
{
	if (v->t[1] != T_REG)
		return (0);
	if (v->t[2] != T_REG)
		if (v->t[2] != DIR_SIZE)
			if (v->t[2] != IND_SIZE)
				return (0);
	if (v->t[3] != T_REG)
		if (v->t[3] != DIR_SIZE)
			return (0);
	if (v->t[2] != T_REG)
		v->t[2] = IND_SIZE;
	if (v->t[3] != T_REG)
		v->t[3] = IND_SIZE;
	return (1);
}

static int		check_regs(t_op_var v)
{
	if (v.t[1] == T_REG)
		if (!valid_reg(v.p[1]))
			return (0);
	if (v.t[2] == T_REG)
		if (!valid_reg(v.p[2]))
			return (0);
	if (v.t[3] == T_REG)
		if (!valid_reg(v.p[3]))
			return (0);
	return (1);
}

static int		pc_forward(int acb)
{
	int i;

	i = 2;
	if (is_register(acb, 0))
		i++;
	else
		i += 2;
	if (is_register(acb, 1))
		i++;
	else
		i += 2;
	if (is_register(acb, 2))
		i++;
	else
		i += 2;
	return (i);
}

static int		do_sti(t_op_var v, int acb, t_process *p, t_core *arena)
{
	int		result;

	result = 0;
	if (is_register(acb, 1) && is_direct(acb, 2))
		result = value_from_reg(p->reg[v.p[2]]) + v.p[3];
	else if (is_register(acb, 1) && is_register(acb, 2))
		result = value_from_reg(p->reg[v.p[2]]) +
			value_from_reg(p->reg[v.p[3]]);
	else if (is_direct(acb, 1) && is_direct(acb, 2))
		result = v.p[2] + v.p[3];
	else if (is_direct(acb, 1) && is_register(acb, 2))
		result = v.p[2] + value_from_reg(p->reg[v.p[3]]);
	else if (is_indirect(acb, 1) && is_direct(acb, 2))
		result = data_var((p->pc + (v.p[2])) % MEM_SIZE, arena, IND_SIZE) +
			v.p[3];
	else if (is_indirect(acb, 1) && is_register(acb, 2))
		result = data_var((p->pc + (v.p[2])) % MEM_SIZE, arena, IND_SIZE) +
			value_from_reg(p->reg[v.p[3]]);
	return (result);
}

int				op_sti(t_process *p, t_core *arena)
{
	t_op_var	v;
	int			res;

	v.acb = arena[(p->pc + 1) % MEM_SIZE].raw;
	init_var(&v);
	if (!check_param_type(&v))
	{
		p->pc = (p->pc + pc_forward(v.acb)) % MEM_SIZE;
		return (0);
	}
	v.p[1] = data_var((p->pc + 2) % MEM_SIZE, arena, v.t[1]);
	v.p[2] = data_var((p->pc + 2 + v.t[1]) % MEM_SIZE, arena, v.t[2]);
	v.p[3] = data_var((p->pc + 2 + v.t[1] + v.t[2]) % MEM_SIZE, arena, v.t[3]);
	if (check_regs(v))
	{
		v.p[1] = value_from_reg(p->reg[v.p[1] - 1]);
		res = do_sti(v, v.acb, p, arena);
		write_to_core(arena, (p->pc + (res % IDX_MOD)) % MEM_SIZE, v.p[1],
				REG_SIZE);
		p->pc = (p->pc + pc_forward(v.acb)) % MEM_SIZE;
		return (1);
	}
	p->pc = (p->pc + pc_forward(v.acb)) % MEM_SIZE;
	return (0);
}
