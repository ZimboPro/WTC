/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:49:02 by prussell          #+#    #+#             */
/*   Updated: 2017/09/21 10:23:44 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_opcode(char *line)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(line, g_op_tab[i].name) == 0)
			return (g_op_tab[i].opcode);
		i++;
	}
	return (0);
}

int		is_label_address(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(LABEL_CHARS, line[i]) == NULL && line[i] != LABEL_CHAR)
			return (0);
		i++;
	}
	if (line[i - 1] == LABEL_CHAR && i > 0)
		return (1);
	return (0);
}

int		is_label_param(char *line)
{
	int	i;

	i = 0;
	if (ft_strchr(line, LABEL_CHAR) == NULL)
	{
		return (0);
	}
	if (line[i] == DIRECT_CHAR)
		i++;
	while (line[i])
	{
		if (ft_strchr(LABEL_CHARS, line[i]) == NULL && line[i] != LABEL_CHAR)
			return (0);
		i++;
	}
	return (1);
}

int		is_param(char *line)
{
	if (is_label_param(line))
		return (1);
	if (*line == DIRECT_CHAR || *line == 'r')
		line++;
	if (!ft_isnumber(line))
		return (0);
	return (1);
}

int		is_comment(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == COMMENT_CHAR)
		return (1);
	return (0);
}
