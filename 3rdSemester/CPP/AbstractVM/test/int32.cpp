/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:13:22 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 11:13:24 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(valid_values_addtion, int32)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *s = *v + *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const *j = *t + *u;
    EXPECT_TRUE(s->getType() == eOperandType::TypeInt32);
    EXPECT_TRUE(s->getPrecision() == 2);
    EXPECT_TRUE(s->toString().compare("10") == 0);
    EXPECT_TRUE(j->toString().compare("5") == 0);
}

TEST(valid_values_subtraction, int32)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *s = *v - *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const *j = *u - *t;
    EXPECT_TRUE(s->getType() == eOperandType::TypeInt32);
    EXPECT_TRUE(s->getPrecision() == 2);
    EXPECT_TRUE(s->toString().compare("0") == 0);
    EXPECT_TRUE(j->toString().compare("-5") == 0);
}

TEST(valid_values_multiplication, int32)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *s = *v * *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const *j = *u * *t;
    EXPECT_EQ(s->toString(), "25");
    EXPECT_EQ(j->toString(), "0");
}

TEST(valid_values_division, int32)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *s = *v / *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const *j = *u / *t;
    EXPECT_EQ(s->toString(), "1");
    EXPECT_EQ(j->toString(), "0");
}

TEST(valid_values_modulus, int32)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt32, "5");
    IOperand const *s = *v % *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt32, "0");
    IOperand const *j = *u % *t;
    EXPECT_EQ(s->toString(), "0");
    EXPECT_EQ(j->toString(), "0");
}
