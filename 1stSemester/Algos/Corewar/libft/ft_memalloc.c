/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:43:36 by prussell          #+#    #+#             */
/*   Updated: 2017/06/06 11:20:51 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = (unsigned char *)malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
