/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:01:16 by prussell          #+#    #+#             */
/*   Updated: 2017/06/08 15:20:15 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s != NULL)
	{
		str = ft_strnew(ft_strlen(s));
		if (str != NULL)
		{
			i = 0;
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
