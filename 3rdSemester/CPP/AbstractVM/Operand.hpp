/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13/04/19 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/22 13/04/19 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
//#include "Factory.hpp"

//class Factory;

template <typename T, eOperandType S>
class Operand : public IOperand
{
  private:
	T _val;
	int _precision;
	eOperandType _type;
	std::string _str;

  public:
	Operand();
	Operand(std::string const &val);

	Operand(Operand const &src);

	virtual ~Operand();

	virtual Operand & operator=(Operand<T, S> const &src);

	virtual int getPrecision(void) const;

	virtual eOperandType getType(void) const;

	virtual IOperand const * operator+(IOperand const &rhs) const;
	virtual IOperand const * operator-(IOperand const &rhs) const;
	virtual IOperand const * operator*(IOperand const &rhs) const;
	virtual IOperand const * operator/(IOperand const &rhs) const;
	virtual IOperand const * operator%(IOperand const &rhs) const;

	virtual std::string const &toString(void) const;

	T const getValue();
	void checkForOverFlow(std::string const & str, eOperandType type);
	bool IsZero(std::string const & str, eOperandType type) const;
};

#include "Operand.cpp"

#endif
