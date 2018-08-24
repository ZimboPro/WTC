/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:05:22 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/21 09:05:26 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"

Factory::Factory()
{
    this->_funcs[eOperandType::TypeInt8] = &Factory::createInt8;
    this->_funcs[eOperandType::TypeInt16] = &Factory::createInt16;
    this->_funcs[eOperandType::TypeInt32] = &Factory::createInt32;
    this->_funcs[eOperandType::TypeFloat] = &Factory::createFloat;
    this->_funcs[eOperandType::TypeDouble] = &Factory::createDouble;
}

Factory::Factory(Factory const &src)
{
    *this = src;
}

Factory::~Factory() {}

Factory &Factory::operator=(Factory const &src)
{
    if (this != &src)
    {
        *this = src;
    }
    return (*this);
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value)
{
    return ((this->*_funcs[type])(value));
}

IOperand const *Factory::createInt8(std::string const &value)
{
    Operand<int8_t, eOperandType::TypeInt8> *o = new Operand<int8_t, eOperandType::TypeInt8>(value);
    return o;
}

IOperand const *Factory::createInt16(std::string const &value)
{
    return new Operand<int16_t, eOperandType::TypeInt16>(value);
}

IOperand const *Factory::createInt32(std::string const &value)
{
    return new Operand<int32_t, eOperandType::TypeInt32>(value);
}

IOperand const *Factory::createFloat(std::string const &value)
{
    return new Operand<float, eOperandType::TypeFloat>(value);
}

IOperand const *Factory::createDouble(std::string const &value)
{
    return new Operand<double, eOperandType::TypeDouble>(value);
}
