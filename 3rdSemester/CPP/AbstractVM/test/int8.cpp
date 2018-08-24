/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:13:09 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 11:13:11 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(valid_values_addtion, int8)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *s = *v + *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *t + *u;
    EXPECT_TRUE(s->getType() == eOperandType::TypeInt8);
    EXPECT_TRUE(s->getPrecision() == 0);
    EXPECT_TRUE(s->toString().compare("10") == 0);
    EXPECT_TRUE(j->toString().compare("5") == 0);
}

TEST(valid_values_subtraction, int8)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *s = *v - *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u - *t;
    EXPECT_TRUE(s->getType() == eOperandType::TypeInt8);
    EXPECT_TRUE(s->getPrecision() == 0);
    EXPECT_TRUE(s->toString().compare("0") == 0);
    EXPECT_TRUE(j->toString().compare("-5") == 0);
}

TEST(valid_values_multiplication, int8)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *s = *v * *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u * *t;
    EXPECT_EQ(s->toString(), "25");
    EXPECT_EQ(j->toString(), "0");
}

TEST(valid_values_division, int8)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt8, "2");
    IOperand const *s = *v / *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u / *t;
    EXPECT_EQ(s->toString(), "2");
    EXPECT_EQ(j->toString(), "0");
}

TEST(valid_values_modulus, int8)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *s = *v % *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u % *t;
    EXPECT_EQ(s->toString(), "0");
    EXPECT_EQ(j->toString(), "0");
}
