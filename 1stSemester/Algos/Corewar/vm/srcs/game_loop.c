/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:32:34 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 15:16:33 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	void	winner(t_env *env, int player_num)
{
	unsigned int	i;

	i = 0;
	while (i < env->num_players)
	{
		if (env->champs[i].player_num == player_num)
		{
			ft_putstr("Player ");
			ft_putnbr(env->champs[i].player_num);
			ft_putchar(' ');
			ft_putstr(env->champs[i].name);
			ft_putendl(" won");
			exit_prog(env);
		}
		i++;
	}
	ft_putendl_fd("No champs called live sucessfully", 2);
}

/*
** Check_processes removes processes that have not made a valid call to live op
** since last check. Also returns NBR_LIVE if one process has made NBR_LIVE
** calls to live op.
*/

void			check_top_proc(t_process **head, int *ret)
{
	while (*head && (*head)->live_calls == 0)
		del_first_proc(head);
	if (*head && (*head)->live_calls >= NBR_LIVE)
	{
		*ret = NBR_LIVE;
		(*head)->live_calls = 0;
	}
}

int				check_processes(t_process **head, int ret)
{
	t_process	*cur;
	t_process	*tmp;

	check_top_proc(head, &ret);
	cur = *head;
	while (cur && cur->next)
	{
		if (cur->next->live_calls >= NBR_LIVE)
			ret = NBR_LIVE;
		if (cur->next->live_calls <= 0)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
		}
		else
		{
			cur->next->live_calls = 0;
			cur = cur->next;
		}
	}
	if (*head)
		(*head)->live_calls = 0;
	return (ret);
}

/*
** run_processes returns the player num of the last process to call live
*/

int				game_loop(t_env *env)
{
	int		c_to_die;
	int		checks;

	c_to_die = CYCLE_TO_DIE;
	checks = 1;
	while (env->process)
	{
		if (env->dump)
			run_processes_dump(env, c_to_die);
		else
			run_processes(env, c_to_die);
		checks++;
		if (check_processes(&env->process, 0) == NBR_LIVE)
		{
			checks = 1;
			c_to_die -= CYCLE_DELTA;
		}
		if (checks == MAX_CHECKS)
		{
			checks = 1;
			c_to_die -= CYCLE_DELTA;
		}
	}
	winner(env, g_last_alive);
	return (0);
}
