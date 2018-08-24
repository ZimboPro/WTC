/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:47:29 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/02 08:36:27 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(fd, &str[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}