/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 07:31:26 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 15:16:19 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		put_live(t_process *p)
{
	ft_putstr("a process shows that player ");
	ft_putnbr(p->player_num);
	ft_putchar(' ');
	ft_putstr(p->player_name);
	ft_putchar(' ');
	ft_putendl("is alive");
}

int			op_live(t_process *p, t_core *arena)
{
	int	param;

	param = data_var((p->pc + 1) % MEM_SIZE, arena, DIR_SIZE);
	p->pc = (p->pc + 1 + DIR_SIZE) % MEM_SIZE;
	if (param == p->player_num)
	{
		p->live_calls++;
		put_live(p);
		g_last_alive = p->player_num;
		return (p->player_num);
	}
	if (param > 0 && param <= MAX_PLAYERS)
		g_last_alive = param;
	return (0);
}
