/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:44:33 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 10:33:34 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_param_type(t_op_var *v)
{
	if (v->t[1] != T_REG)
		if (v->t[1] != DIR_SIZE)
			if (v->t[1] != IND_SIZE)
				return (0);
	if (v->t[2] != T_REG)
		if (v->t[2] != DIR_SIZE)
			return (0);
	if (v->t[3] != T_REG)
		return (0);
	else
	{
		if (v->t[1] != T_REG)
			v->t[1] = IND_SIZE;
		if (v->t[2] != T_REG)
			v->t[2] = IND_SIZE;
	}
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

static int		do_ldi(t_op_var v, int acb, t_process *p, t_core *arena)
{
	int		result;

	result = 0;
	if (is_register(acb, 0) && is_direct(acb, 1))
		result = value_from_reg(p->reg[v.p[1]]) + v.p[2];
	else if (is_register(acb, 0) && is_register(acb, 1))
		result = value_from_reg(p->reg[v.p[1]]) +
			value_from_reg(p->reg[v.p[2]]);
	else if (is_direct(acb, 0) && is_direct(acb, 1))
		result = v.p[1] + v.p[2];
	else if (is_direct(acb, 0) && is_register(acb, 1))
		result = v.p[1] + value_from_reg(p->reg[v.p[2]]);
	else if (is_indirect(acb, 0) && is_direct(acb, 1))
		result = data_var((p->pc + (v.p[1])) % MEM_SIZE, arena, IND_SIZE) +
			v.p[2];
	else if (is_indirect(acb, 0) && is_register(acb, 1))
		result = data_var((p->pc + (v.p[1])) % MEM_SIZE, arena, IND_SIZE) +
			value_from_reg(p->reg[v.p[2]]);
	return (result);
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

int				op_lldi(t_process *p, t_core *arena)
{
	t_op_var	v;
	int			acb;

	v.acb = data_var((p->pc + 1) % MEM_SIZE, arena, T_REG);
	acb = v.acb;
	init_var(&v);
	if (!check_param_type(&v))
	{
		p->pc = (p->pc + pc_forward(acb)) % MEM_SIZE;
		return ((p->carry = 0));
	}
	v.p[1] = data_var((p->pc + 2) % MEM_SIZE, arena, v.t[1]);
	v.p[2] = data_var((p->pc + 2 + v.t[1]) % MEM_SIZE, arena, v.t[2]);
	v.p[3] = data_var((p->pc + 2 + v.t[1] + v.t[2]) % MEM_SIZE, arena, v.t[3]);
	if (check_regs(v))
	{
		write_to_reg(p->reg[v.p[3]], data_var(p->pc +
					(do_ldi(v, acb, p, arena)) % MEM_SIZE, arena, REG_SIZE));
		p->pc = (p->pc + pc_forward(acb)) % MEM_SIZE;
		return ((p->carry = 1));
	}
	p->pc = (p->pc + pc_forward(acb)) % MEM_SIZE;
	return ((p->carry = 0));
}
