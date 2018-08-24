/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 09:50:00 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 13:45:22 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void				clean_reg(
		unsigned char reg[REG_NUMBER + 1][REG_SIZE + 1])
{
	int	i;

	i = 0;
	while (i < REG_NUMBER + 1)
		ft_bzero(reg[i++], REG_SIZE + 1);
}

static t_process		*new_proc_from_champ(t_champ *champ)
{
	t_process	*new;

	if ((new = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	new->pc = champ->pc;
	new->player_name = champ->name;
	new->player_num = champ->player_num;
	new->carry = 0;
	new->cycles_to_exec = 0;
	new->live_calls = 0;
	new->cycles_to_exec = 0;
	clean_reg(new->reg);
	write_to_reg(new->reg[0], champ->player_num);
	new->next = NULL;
	return (new);
}

t_process				*init_process(t_champ *champs, int num_champs)
{
	int			i;
	int			j;
	t_process	*new;
	t_process	*head;

	j = 1;
	head = NULL;
	while (j <= MAX_PLAYERS)
	{
		i = 0;
		while (i < num_champs)
		{
			if (champs[i].player_num == j)
			{
				if ((new = new_proc_from_champ(champs + i)) == NULL)
					return (NULL);
				push_proc(&head, new);
			}
			i++;
		}
		j++;
	}
	return (head);
}
