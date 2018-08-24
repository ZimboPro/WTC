/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:39:56 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 11:39:30 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_processes(t_process *p)
{
	t_process *cur;
	t_process *tmp;

	cur = p;
	while (cur)
	{
		tmp = cur;
		cur = tmp->next;
		free(tmp);
	}
}

void		exit_prog(t_env *env)
{
	free_processes(env->process);
	exit(0);
}
