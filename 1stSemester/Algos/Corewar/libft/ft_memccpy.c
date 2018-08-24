/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:19:55 by prussell          #+#    #+#             */
/*   Updated: 2017/06/09 16:45:03 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		if (*((char *)src + i) == (char)c)
		{
			return ((char *)dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
