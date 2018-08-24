/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:13:48 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 11:13:49 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(valid_values_addtion, DOUBLE)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeDouble, "5.5");
    IOperand const *s = *v + *t;
    IOperand const *u = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const *x = f.createOperand(eOperandType::TypeDouble, "0.5");
    IOperand const *j = *t + *u;
    IOperand const *k = *t + *x;
    EXPECT_EQ(s->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(s->getPrecision(), eOperandType::TypeDouble);
    EXPECT_EQ(s->toString(), "10.500000");
    EXPECT_EQ(j->toString(), "5.500000");
    EXPECT_EQ(k->toString(), "6.000000");
}

TEST(valid_values_subtraction, Double)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeDouble, "5.5");
    IOperand const *s = *v - *t;
    IOperand const *u = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const *x = f.createOperand(eOperandType::TypeDouble, "0.5");
    IOperand const *j = *t - *u;
    IOperand const *k = *t - *x;
    EXPECT_EQ(s->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(s->getPrecision(), eOperandType::TypeDouble);
    EXPECT_EQ(s->toString(), "-0.500000");
    EXPECT_EQ(j->toString(), "5.500000");
    EXPECT_EQ(k->toString(), "5.000000");
}

TEST(valid_values_multiplication, Double)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *s = *v * *t;
    IOperand const *u = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const *j = *u * *t;
    EXPECT_EQ(s->toString(), "25.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}

TEST(valid_values_division, Double)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *s = *v / *t;
    IOperand const *u = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const *j = *u / *t;
    EXPECT_EQ(s->toString(), "1.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}

TEST(valid_values_modulus, Double)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *s = *v % *t;
    IOperand const *u = f.createOperand(eOperandType::TypeDouble, "0");
    IOperand const *j = *u % *t;
    EXPECT_EQ(s->toString(), "0.000000");
    EXPECT_EQ(j->toString(), "0.000000");
}
