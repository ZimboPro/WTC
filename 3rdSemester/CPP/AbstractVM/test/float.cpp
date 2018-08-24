/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:13:33 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 11:13:34 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(valid_values_addtion, Float)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeFloat, "5.5");
    IOperand const *s = *v + *t;
    IOperand const *u = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const *x = f.createOperand(eOperandType::TypeFloat, "0.5");
    IOperand const *j = *t + *u;
    IOperand const *k = *t + *x;
    EXPECT_TRUE(s->getType() == eOperandType::TypeFloat);
    EXPECT_TRUE(s->getPrecision() == 3);
    EXPECT_TRUE(s->toString().compare("10.500000") == 0);
    EXPECT_EQ(j->toString(), "5.500000");
    EXPECT_TRUE(k->toString().compare("6.000000") == 0);
}

TEST(valid_values_subtraction, Float)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeFloat, "5.5");
    IOperand const *s = *v - *t;
    IOperand const *u = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const *x = f.createOperand(eOperandType::TypeFloat, "0.5");
    IOperand const *j = *t - *u;
    IOperand const *k = *t - *x;
    EXPECT_EQ(s->getType(), eOperandType::TypeFloat);
    EXPECT_EQ(s->getPrecision(), eOperandType::TypeFloat);
    EXPECT_EQ(s->toString(), "-0.500000");
    EXPECT_EQ(j->toString(), "5.500000");
    EXPECT_EQ(k->toString(), "5.000000");
}

TEST(valid_values_multiplication, Float)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *s = *v * *t;
    IOperand const *u = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const *j = *u * *t;
    EXPECT_EQ(s->toString(), "25.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}

TEST(valid_values_division, Float)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *s = *v / *t;
    IOperand const *u = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const *j = *u / *t;
    EXPECT_EQ(s->toString(), "1.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}

TEST(valid_values_modulus, Float)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *s = *v % *t;
    IOperand const *u = f.createOperand(eOperandType::TypeFloat, "0");
    IOperand const *j = *u % *t;
    EXPECT_EQ(s->toString(), "0.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}
