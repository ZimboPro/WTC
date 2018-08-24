/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:05:20 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 12:18:31 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_var(t_op_var *v)
{
	int	i;

	i = 1;
	ft_bzero(v->p, MAX_ARGS_NUMBER);
	ft_bzero(v->t, MAX_ARGS_NUMBER);
	while (i < MAX_ARGS_NUMBER)
	{
		if (is_register(v->acb, i - 1))
			v->t[i] = T_REG;
		else if (is_direct(v->acb, i - 1))
			v->t[i] = DIR_SIZE;
		else if (is_indirect(v->acb, i - 1))
			v->t[i] = IND_SIZE;
		else
			v->t[i] = 0;
		i++;
	}
}
