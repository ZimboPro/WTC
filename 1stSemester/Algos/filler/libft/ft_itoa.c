/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:22:48 by lde-jage          #+#    #+#             */
/*   Updated: 2017/06/20 09:59:26 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int	temp;
	int	i;

	temp = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		temp = -temp;
	}
	while (temp > 0)
	{
		i++;
		temp = temp / 10;
	}
	return (i);
}

static char		*ft_min(void)
{
	char	*str;

	str = (char *)malloc(12);
	if (str == NULL)
		return (NULL);
	str = "-2147483648\0";
	return (str);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		size;
	int		chk;

	if (n == INT_MIN)
		return (ft_min());
	size = ft_size(n);
	dest = (char *)malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	chk = 0;
	if (n < 0)
	{
		chk = 1;
		dest[0] = '-';
		n = -n;
	}
	while (size - 1 - chk >= 0)
	{
		dest[size - 1] = n % 10 + 48;
		n = (n - n % 10) / 10;
		size--;
	}
	return (dest);
}
