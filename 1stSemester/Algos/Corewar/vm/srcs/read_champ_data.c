/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:38:36 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 15:39:52 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_magic(t_champ *champ)
{
	int		magic;

	magic = 0;
	if (read(champ->fd, &magic, sizeof(COREWAR_EXEC_MAGIC)) == -1)
		return (-1);
	magic = little_to_big_endian(magic);
	if (magic == COREWAR_EXEC_MAGIC)
		return (0);
	return (-1);
}

static int		get_name_and_size(t_champ *champ)
{
	int		i;
	char	buf;
	int		size;

	i = 0;
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC), SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i <= PROG_NAME_LENGTH && buf)
		champ->name[i++] = buf;
	if (i == PROG_NAME_LENGTH)
	{
		ft_putendl_fd("Name too big", 2);
		return (-1);
	}
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) +
				PROG_NAME_LENGTH + 4, SEEK_SET) < 0)
		return (-1);
	size = 0;
	if (read(champ->fd, &size, sizeof(int)) == -1)
		return (-1);
	champ->stated_size = little_to_big_endian(size);
	return (0);
}

static int		get_comment(t_champ *champ)
{
	int		i;
	char	buf;

	i = 0;
	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH
	+ sizeof(int) + 4, SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i <= COMMENT_LENGTH && buf)
		champ->comment[i++] = buf;
	if (i == COMMENT_LENGTH)
	{
		ft_putendl_fd("Comment too big", 2);
		return (-1);
	}
	return (0);
}

static int		get_champion(t_champ *champ, int i)
{
	char	buf;

	if (lseek(champ->fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH
	+ sizeof(int) + 8 + COMMENT_LENGTH, SEEK_SET) < 0)
		return (-1);
	while (read(champ->fd, &buf, 1) > 0 && i <= CHAMP_MAX_SIZE)
		champ->code[i++] = buf;
	if (i == CHAMP_MAX_SIZE)
	{
		ft_putendl_fd("Champ too big", 2);
		return (-1);
	}
	champ->size = i;
	if (champ->size != champ->stated_size)
		return (champ_size());
	if (champ->code[0] == 0)
	{
		ft_putendl_fd("No champs code", 2);
		return (-1);
	}
	return (0);
}

int				read_champ_data(t_env *env, int num_champs)
{
	int	i;

	i = 0;
	while (i < num_champs)
	{
		if (check_magic(&env->champs[i]) < 0 ||
				get_name_and_size(&env->champs[i]) < 0 ||
				get_comment(&env->champs[i]) < 0 ||
				get_champion(&env->champs[i], 0) < 0)
			return (-1);
		else if (close(env->champs[i].fd) < 0)
			return (-1);
		i++;
	}
	return (0);
}
