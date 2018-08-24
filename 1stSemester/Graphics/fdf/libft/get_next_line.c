/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:43:47 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/29 10:47:20 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static char	*ft_search(char **s1, t_gnl *gnl)
{
	if (gnl->cur == '\0')
		gnl->cur = 0;
	if (gnl->line == '\0')
	{
		gnl->line = 0;
		while (gnl->str[gnl->line] != '\0')
			gnl->line = gnl->line + 1;
	}
	if (gnl->cur < gnl->line)
	{
		gnl->cur = gnl->cur + 1;
		s1[0] = ft_strdup(gnl->str[gnl->cur - 1]);
		return (s1[0]);
	}
	return (NULL);
}

static char	*ft_realloc(char *str, size_t j)
{
	char	*temp;

	temp = (char *)malloc(j + BUF_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	temp = ft_strncpy(temp, str, j);
	ft_memdel((void *)&str);
	return (temp);
}

static char	*ft_get_line(int fd, void *buf)
{
	ssize_t	i;
	ssize_t	rd;
	size_t	j;
	char	*s;

	rd = 0;
	j = 0;
	if ((s = (char*)malloc(BUF_SIZE + 1)) == NULL)
		return (NULL);
	while ((rd = read(fd, buf, BUF_SIZE)) > 0)
	{
		i = 0;
		while (i < rd)
		{
			if (j % BUF_SIZE == 0)
				s = ft_realloc(s, j);
			s[j] = ((unsigned char *)buf)[i];
			i++;
			j++;
		}
	}
	if (rd < 0)
		return (NULL);
	s[j] = '\0';
	return (s);
}

static void	ft_free(char **s, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		ft_strdel(&s[i]);
		i++;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	char			*s;
	int				i;

	gnl.ret = 1;
	i = 0;
	if (BUF_SIZE < 1 || line == NULL || (gnl.buf = malloc(BUF_SIZE)) == NULL
		|| fd < 0)
		return (-1);
	if (gnl.str == NULL || gnl.fd_temp != fd)
	{
		gnl.fd_temp = fd;
		if ((s = ft_get_line(fd, gnl.buf)) == NULL)
			return (-1);
		gnl.str = ft_strsplit(s, '\n');
		ft_strdel(&s);
	}
	if ((line[0] = ft_search(line, &gnl)) == NULL)
		gnl.ret = 0;
	ft_memdel(&gnl.buf);
	if (gnl.str[i] != NULL && gnl.ret == 0)
		ft_free(gnl.str, gnl.line);
	return (gnl.ret);
}
