/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:14:10 by prussell          #+#    #+#             */
/*   Updated: 2017/10/01 10:14:00 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_reg(unsigned char *reg, int value)
{
	int				i;
	int				t;

	i = 0;
	while (i < REG_SIZE)
	{
		t = value >> (24 - 8 * i) & 0xFF;
		reg[i] = t;
		i++;
	}
	reg[i] = '\0';
}

int		value_from_reg(unsigned char *reg)
{
	int		k;
	int		j;
	char	num[REG_SIZE * 2 + 1];

	ft_bzero(num, REG_SIZE * 2 + 1);
	k = 0;
	j = 0;
	while (j < REG_SIZE)
	{
		write_char_to_hex(reg[j], num + k);
		k += 2;
		j++;
	}
	return (ft_htoi(num, REG_SIZE * 2));
}
