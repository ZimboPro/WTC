/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13/04/19 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/22 13/04/19 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <math.h>
#include <cfloat>
#include <limits>
#include <cstdint>
#include "Operand.hpp"
#include "Factory.hpp"

template <typename T, eOperandType S>
void Operand<T, S>::checkForOverFlow(std::string const & str, eOperandType type)
{
    size_t t;
    long double temp = std::stold(str, &t);
    switch (type)
    {
        case eOperandType::TypeInt8 :
            if (temp < INT8_MIN)
                throw (Error::UnderFlow());
            if (temp > INT8_MAX)
                throw (Error::OverFlow());
            break;
        case eOperandType::TypeInt16 :
            if (temp < INT16_MIN)
                throw (Error::UnderFlow());
            if (temp > INT16_MAX)
                throw (Error::OverFlow());
            break;
        case eOperandType::TypeInt32 :
            if (temp < INT32_MIN)
                throw (Error::UnderFlow());
            if (temp > INT32_MAX)
                throw (Error::OverFlow());
            break;
        case eOperandType::TypeFloat :
            if (temp < -(std::numeric_limits<float>::max() + 1))
                throw (Error::UnderFlow());
            if (temp > std::numeric_limits<float>::max())
                throw (Error::OverFlow());
            break;
        case eOperandType::TypeDouble :
            if (temp < -(std::numeric_limits<double>::max() + 1))
                throw (Error::UnderFlow());
            if (temp > std::numeric_limits<double>::max())
                throw (Error::OverFlow());
            break;
    }
}

template <typename T, eOperandType S>
Operand<T, S>::Operand()
{
    this->_precision = 0;
    this->_type = 0;
    this->_val = 0;
    this->_str = "0";
}

template <typename T, eOperandType S>
Operand<T, S>::Operand(std::string const & val) : _precision(S), _type(S)
{
    checkForOverFlow(val, S);
    std::size_t t;
    this->_val = static_cast<T>(stold(val, &t));
    this->_str = std::to_string(this->_val);
}

template <typename T, eOperandType S>
Operand<T, S>::Operand(Operand const &src)
{
    if (this != &src)
    {
        *this = src;
    }
}

template <typename T, eOperandType S>
Operand<T, S>::~Operand(){}

template <typename T, eOperandType S>
Operand<T, S> & Operand<T, S>::operator=(Operand<T, S> const &src)
{
    if (this != &src)
    {
        this->_precision = src._precision;
        this->_type = src._type;
        this->_val = src._val;
    }
    return (*this);
}

template <typename T, eOperandType S>
int Operand<T, S>::getPrecision(void) const
{
    return (this->_precision);
}

template <typename T, eOperandType S>
eOperandType Operand<T, S>::getType(void) const
{
    return (this->_type);
}
template <typename T, eOperandType S>
IOperand const * Operand<T, S>::operator+(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_val + temp);
    ans = convert.str();

    Factory fa;

    if (this->_precision < rhs.getPrecision())
    {
        return fa.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return fa.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * Operand<T, S>::operator-(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_val - temp);
    ans = convert.str();

    Factory fa;

    if (this->_precision < rhs.getPrecision())
    {
        return fa.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return fa.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * Operand<T, S>::operator*(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_val * temp);
    ans = convert.str();

    Factory fa;

    if (this->_precision < rhs.getPrecision())
    {
        return fa.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return fa.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
bool Operand<T, S>::IsZero(std::string const & str, eOperandType type) const
{
    size_t t;
    long double temp = stold(str, &t);
    switch (type)
    {
        case eOperandType::TypeInt8 :
            if (static_cast<int8_t>(0) == static_cast<int8_t>(temp))
                return true;
            break;
        case eOperandType::TypeInt16 :
            if (static_cast<int16_t>(0) == static_cast<int16_t>(temp))
                return true;
            break;
        case eOperandType::TypeInt32 :
            if (static_cast<int32_t>(0) == static_cast<int32_t>(temp))
                return true;
            break;
        case eOperandType::TypeFloat :
            if (static_cast<float>(0) == static_cast<float>(temp))
                return true;
            break;
        case eOperandType::TypeDouble :
            if (static_cast<double>(0) == static_cast<double>(temp))
                return true;
            break;
    }
    return false;
}

template <typename T, eOperandType S>
IOperand const * Operand<T, S>::operator/(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_val / temp);
    ans = convert.str();
    if (IsZero(rhs.toString(), rhs.getType()))
        throw Error::DivBy0();
    Factory fa;

    if (this->_precision < rhs.getPrecision())
    {
        return fa.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return fa.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * Operand<T, S>::operator%(IOperand const &rhs) const
{
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    std::string ans = std::to_string(static_cast<T>(fmod(this->_val, temp)));
    if (this->IsZero(rhs.toString(), rhs.getType()))
        throw Error::ModBy0();
    Factory fa;

    if (this->_precision < rhs.getPrecision())
    {
        return fa.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return fa.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
std::string const & Operand<T, S>::toString(void) const
{
    return (this->_str);
}

template <typename T, eOperandType S>
T const Operand<T, S>::getValue()
{
    return (this->_val);
}
