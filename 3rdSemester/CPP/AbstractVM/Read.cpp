/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06/18/48 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 06/18/48 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Read.hpp"

Read::Read() {}

Read::Read(Read const & src)
{
	*this = src;	
}

Read::~Read() {}

Read & Read::operator=(Read const & src)
{
	if (this != &src)
    {
		*this = src;
    }
	return (*this);
}

