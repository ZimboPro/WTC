/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:03:10 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/29 14:19:45 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		pc_counter(int pc, int acb, int param_num)
{
	if (is_direct(acb, param_num) == 1)
		return ((pc + DIR_SIZE) % MEM_SIZE);
	else if (is_indirect(acb, param_num) == 1)
		return ((pc + IND_SIZE) % MEM_SIZE);
	return ((pc + T_REG) % MEM_SIZE);
}
