/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:24:29 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 11:28:29 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		cpy_reg(unsigned char src[REG_NUMBER + 1][REG_SIZE + 1],
		unsigned char dst[REG_NUMBER + 1][REG_SIZE + 1])
{
	int	i;
	int	j;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		j = 0;
		while (j < REG_SIZE + 1)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

t_process		*new_proc(t_process *father, int pc)
{
	t_process	*new;

	new = NULL;
	if ((new = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	new->pc = pc;
	new->player_num = father->player_num;
	new->player_name = father->player_name;
	new->carry = father->carry;
	new->cycles_to_exec = 0;
	new->live_calls = 0;
	cpy_reg(father->reg, new->reg);
	new->next = NULL;
	return (new);
}

void			push_proc(t_process **head, t_process *p)
{
	p->next = *head;
	*head = p;
}

void			append_proc(t_process *head, t_process *new)
{
	t_process *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void			del_first_proc(t_process **head)
{
	t_process *next_node;

	next_node = NULL;
	if (*head != NULL)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}
}
