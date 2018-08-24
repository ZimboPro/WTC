/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:54:29 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 13:54:34 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(overflow, combination)
{
    Factory f;
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt8, "10000"), Error::OverFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt16, "1000000"), Error::OverFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt32, "10000000000000"), Error::OverFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeFloat, "10000000000000000000000000000000000000000000000000000000000000000000000"), Error::OverFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt8, "-10000"), Error::UnderFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt16, "-1000000"), Error::UnderFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeInt32, "-10000000000000"), Error::UnderFlow);
    EXPECT_THROW(f.createOperand(eOperandType::TypeFloat, "-10000000000000000000000000000000000000000000000000000000000000000000000"), Error::UnderFlow);
}

TEST(divby0, combination)
{
    Factory f;
    IOperand const * a = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const * b = f.createOperand(eOperandType::TypeInt16, "0");
    IOperand const * c = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const * d = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const * e = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const * g = f.createOperand(eOperandType::TypeDouble, "100");
    EXPECT_THROW(*g / *a, Error::DivBy0);
    EXPECT_THROW(*g / *b, Error::DivBy0);
    EXPECT_THROW(*g / *c, Error::DivBy0);
    EXPECT_THROW(*g / *d, Error::DivBy0);
    EXPECT_THROW(*g / *e, Error::DivBy0);
}

TEST(modby0, combination)
{
    Factory f;
    IOperand const * a = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const * b = f.createOperand(eOperandType::TypeInt16, "0");
    IOperand const * c = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const * d = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const * e = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const * g = f.createOperand(eOperandType::TypeDouble, "100");
    EXPECT_THROW(*g % *a, Error::ModBy0);
    EXPECT_THROW(*g % *b, Error::ModBy0);
    EXPECT_THROW(*g % *c, Error::ModBy0);
    EXPECT_THROW(*g % *d, Error::ModBy0);
    EXPECT_THROW(*g % *e, Error::ModBy0);
}
