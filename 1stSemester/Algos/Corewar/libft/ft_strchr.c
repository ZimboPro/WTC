/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:33:43 by prussell          #+#    #+#             */
/*   Updated: 2017/06/02 08:23:48 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int n;

	n = ft_strlen(s);
	i = 0;
	while (i < n && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)(s + i));
	else
		return (NULL);
}
