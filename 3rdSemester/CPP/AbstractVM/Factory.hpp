/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:05:48 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/21 09:05:54 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FACTORY_HPP
# define	FACTORY_HPP

#include <iostream>
#include "IOperand.hpp"

// template<typename T, eOperandType S>
// class Operand;

class Factory {
	private:
		IOperand const * (Factory::*_funcs[5])(std::string const & value);

		IOperand const * createInt8( std::string const & value );

		IOperand const * createInt16( std::string const & value );

		IOperand const * createInt32( std::string const & value );

		IOperand const * createFloat( std::string const & value );

		IOperand const * createDouble( std::string const & value );

	public:

		Factory();

		Factory(Factory const & src);

		~Factory();

		Factory & operator=(Factory const & src);

		IOperand const * createOperand(eOperandType type, std::string const & value );

};

#endif
