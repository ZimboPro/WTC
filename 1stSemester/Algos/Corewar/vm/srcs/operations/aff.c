/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:32:39 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 15:40:07 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			op_aff(t_process *p, t_core *arena)
{
	int		acb;
	int		val;
	int		reg_data;

	acb = data_var((p->pc + 1) % MEM_SIZE, arena, T_REG);
	if (is_register(acb, 0))
	{
		val = data_var((p->pc + 2) % MEM_SIZE, arena, T_REG);
		if (valid_reg(val))
		{
			reg_data = value_from_reg(p->reg[val - 1]);
			ft_putchar(reg_data % 256);
			p->pc = (p->pc + 3) % MEM_SIZE;
			return (1);
		}
	}
	p->pc = pc_counter(p->pc + 1, acb, 0);
	return (0);
}
