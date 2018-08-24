/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:56:22 by prussell          #+#    #+#             */
/*   Updated: 2017/09/23 09:02:09 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	swap_two_octets(int nb)
{
	int	tmp;

	tmp = nb & 0xff;
	nb = (nb & 0xff00) / 0xff;
	nb = nb + (tmp * 0x100);
	return (nb);
}

int			little_to_big_endian(int nb)
{
	int		tmp;

	tmp = nb & 0xffff;
	nb = (nb & 0xffff0000) / 0xffff;
	tmp = swap_two_octets(tmp) * 0x10000;
	nb = swap_two_octets(nb) + tmp;
	return (nb);
}
