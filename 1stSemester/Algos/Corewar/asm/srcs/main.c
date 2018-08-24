/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:34:03 by prussell          #+#    #+#             */
/*   Updated: 2017/09/30 12:27:22 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_size(int fd)
{
	char	*buffer;
	int		i;
	int		n;

	n = 0;
	i = 0;
	buffer = ft_strnew(42);
	while (read(fd, buffer, 42) != 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				n++;
			i++;
		}
	}
	ft_strdel(&buffer);
	lseek(fd, 0, SEEK_SET);
	return (n);
}

void	free_lines(t_src_line *lines)
{
	int	i;
	int	p;

	i = 0;
	while (lines[i].num != -1)
	{
		if (lines[i].label != NULL)
			free(lines[i].label);
		p = 0;
		while (lines[i].params[p] != NULL)
		{
			if (lines[i].params[p] != NULL)
				free(lines[i].params[p]);
			p++;
		}
		i++;
	}
	free(lines);
}

void	main_part_two(int fd, char **argv)
{
	t_src_line	*lines;
	t_binary	bin;
	int			n;

	n = get_size(fd);
	lines = build_line_data_struct(fd, n);
	lseek(fd, 0, SEEK_SET);
	init_bin_var(&bin, fd, argv[1]);
	champ_size(lines, &bin);
	if (close(fd) != 0)
	{
		ft_putendl_fd("Could not close file", 2);
		exit(-5);
	}
	if (check_errors(lines) == 1)
	{
		ft_putendl("Errors detected, aborting compilation");
		free_lines(lines);
		free(bin.name);
		exit(-4);
	}
	ft_putstr("No errors detected, Proceeding with compilation\n");
	write_cor(lines, &bin);
	free(bin.name);
	free_lines(lines);
}

int		main(int argc, char **argv)
{
	int			fd;

	if (argc == 1)
	{
		ft_putendl_fd("Usage: ./asm [Path to filename.s] ...", 2);
		return (-1);
	}
	else if ((fd = open(argv[1], O_RDONLY)) < 1)
	{
		ft_putendl_fd("Could not open file", 2);
		return (-2);
	}
	else if (is_valid_fd(fd))
	{
		ft_putstr("Assembling ");
		ft_putendl(argv[1]);
		main_part_two(fd, argv);
	}
	else
		return (-3);
	return (0);
}
