/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:59:39 by dbarrow           #+#    #+#             */
/*   Updated: 2017/09/30 07:39:11 by dbarrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_error(char *str, int line_num)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" at line no: ", 2);
	ft_putnbr_fd(line_num + 1, 2);
	ft_putchar_fd('\n', 2);
}
