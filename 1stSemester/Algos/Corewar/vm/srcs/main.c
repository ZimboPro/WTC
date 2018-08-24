/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:56:50 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 15:37:21 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	read_cor_error(void)
{
	ft_putendl_fd("Read .cor error", 2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env		env;
	t_process	*cur;

	if (argc == 1 || init_env(argc, argv, &env) < 0)
	{
		ft_putendl_fd(P_E, 2);
		return (-1);
	}
	if (read_champ_data(&env, env.num_players) < 0)
		return (read_cor_error());
	read_champs_into_core(&env);
	if ((env.process = init_process(env.champs, env.num_players)) == NULL)
	{
		ft_putendl_fd("Process init error", 2);
		return (-1);
	}
	cur = env.process;
	while (cur)
	{
		cur->carry = 1;
		exec_proc(cur, env.arena);
		cur = cur->next;
	}
	game_loop(&env);
	return (0);
}
