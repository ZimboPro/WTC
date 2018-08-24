/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:56:18 by lde-jage          #+#    #+#             */
/*   Updated: 2017/10/01 14:56:23 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_char_to_hex(unsigned char num, char *reg)
{
	char	hex[16];

	ft_strcpy(hex, "0123456789ABCDEF");
	if (num < 16)
	{
		reg[0] = '0';
		reg[1] = hex[num];
	}
	else
	{
		reg[0] = hex[(num / 16) % 16];
		reg[1] = hex[num % 16];
	}
}

void	all_zero(char *str, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		str[i] = '0';
		i++;
	}
}

int		champ_size(void)
{
	ft_putendl_fd("Invalid champ size in header", 2);
	return (-1);
}
