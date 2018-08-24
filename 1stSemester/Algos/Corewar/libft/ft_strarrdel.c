/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:14:17 by lde-jage          #+#    #+#             */
/*   Updated: 2017/09/28 15:57:29 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_strarrdel(char **str)
{
	int		i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != NULL)
		{
			ft_strdel(&str[i]);
			i++;
		}
	}
	free(str);
}
