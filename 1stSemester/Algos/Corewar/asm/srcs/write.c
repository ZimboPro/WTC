/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 09:07:14 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 12:23:41 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic(int fd)
{
	int magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	write(fd, (char *)&magic, 4);
}

void	write_name_comment(t_binary *bin)
{
	char			buf[8];
	unsigned int	n;

	n = bin->header.prog_size;
	ft_bzero(buf, 8);
	write(bin->fd, bin->header.prog_name, PROG_NAME_LENGTH);
	write(bin->fd, buf, 4);
	n = ((n >> 24) & 0xff) | ((n << 8) & 0xff0000) |
		((n >> 8) & 0xff00) | ((n << 24) & 0xff000000);
	write(bin->fd, (char *)&n, 4);
	write(bin->fd, bin->header.comment, COMMENT_LENGTH);
	write(bin->fd, buf, 4);
}

void	write_header(t_binary *bin)
{
	write_magic(bin->fd);
	write_name_comment(bin);
}

int		write_cor(t_src_line *lines, t_binary *bin)
{
	if (!(bin->fd = open(bin->name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
	{
		ft_putstr_fd("Could not open .cor file", 2);
		return (-1);
	}
	else
	{
		write_header(bin);
		write_bytes(bin->fd, lines);
		close(bin->fd);
	}
	return (0);
}
