/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:05:41 by prussell          #+#    #+#             */
/*   Updated: 2017/07/29 09:41:25 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j] && big[i] != '\0')
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + (i - j)));
		else
			i -= (j);
		i++;
	}
	return (NULL);
}
