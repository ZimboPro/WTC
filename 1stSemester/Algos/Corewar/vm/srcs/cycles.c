/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 07:19:38 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 10:49:03 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cyc(unsigned char op)
{
	if (op < 17 && op > 0)
	{
		return (g_op_tab[op - 1].nb_cycles);
	}
	return (0);
}
