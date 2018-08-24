/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:33:33 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 12:29:14 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	read_in_comment(char *line, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"' && line[++i])
		while (line[i] && line[i] != '"' && j < COMMENT_LENGTH)
			name[j++] = line[i++];
	if (line[i] != '"')
		ft_putendl_fd("Problem with comment", 2);
}

static void	read_in_name(char *line, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"' && line[++i])
		while (line[i] && line[i] != '"' && j < PROG_NAME_LENGTH)
			name[j++] = line[i++];
	if (line[i] != '"')
		ft_putendl_fd("Problem with name", 2);
}

int			init_header_var(t_header *head, int fd)
{
	char	*line;
	int		name_found;
	int		comment_found;

	ft_bzero(head->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->comment, COMMENT_LENGTH + 1);
	head->magic = COREWAR_EXEC_MAGIC;
	head->prog_size = 0;
	name_found = 0;
	comment_found = 0;
	while ((!name_found || !comment_found) && get_next_line(fd, &line))
	{
		if (line && ft_strstr(line, NAME_CMD_STRING) && (name_found = 1))
			read_in_name(line, head->prog_name);
		else if (line && ft_strstr(line, COMMENT_CMD_STRING) &&
				(comment_found = 1))
			read_in_comment(line, head->comment);
		ft_strdel(&line);
	}
	return (0);
}

char		*exe_name(char *name)
{
	t_norm	norm;

	norm.i = 0;
	norm.j = 0;
	if (!(norm.split = ft_strsplit(name, '/')))
		return (NULL);
	while (norm.split[norm.j])
		norm.j++;
	norm.j--;
	while (norm.split[norm.j][norm.i] && norm.split[norm.j][norm.i] != '.')
		norm.i++;
	if (norm.split[norm.j][norm.i] != '.' ||
			!(norm.exe = (char *)malloc(sizeof(char) * (norm.i))))
		return (NULL);
	norm.i = 0;
	while (norm.split[norm.j][norm.i] != '.')
	{
		norm.exe[norm.i] = norm.split[norm.j][norm.i];
		norm.i++;
	}
	ft_strcat(norm.exe + norm.i, ".cor");
	ft_strarrdel(norm.split);
	return (norm.exe);
}

int			init_bin_var(t_binary *bin, int fd, char *name)
{
	init_header_var(&(bin->header), fd);
	bin->name = exe_name(name);
	ft_putendl(bin->header.prog_name);
	ft_putendl(bin->header.comment);
	return (1);
}
