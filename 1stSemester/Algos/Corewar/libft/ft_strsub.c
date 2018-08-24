/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:36:55 by prussell          #+#    #+#             */
/*   Updated: 2017/06/08 15:22:29 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len);
	if (dst != NULL)
	{
		i = 0;
		while (i < len)
			dst[i++] = s[start++];
		return (dst);
	}
	return (NULL);
}
