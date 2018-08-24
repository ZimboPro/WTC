/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:31:59 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/26 13:32:00 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

TEST(addition, combination)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt16, "5");
    IOperand const *s = *v + *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *t + *u;
    EXPECT_EQ(s->toString(), "10");
    EXPECT_EQ(s->getType(), eOperandType::TypeInt16);
    EXPECT_EQ(j->toString(), "5");
    EXPECT_EQ(j->getType(), eOperandType::TypeInt16);
    IOperand const *a = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *b = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *c = *v + *a;
    IOperand const *d = *b + *t;
    EXPECT_EQ(c->toString(), "10.000000");
    EXPECT_EQ(c->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(d->toString(), "10.000000");
    EXPECT_EQ(d->getType(), eOperandType::TypeFloat);
}

TEST(subtraction, combination)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt16, "5");
    IOperand const *s = *v - *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *t - *u;
    EXPECT_EQ(s->toString(), "0");
    EXPECT_EQ(s->getType(), eOperandType::TypeInt16);
    EXPECT_EQ(j->toString(), "5");
    EXPECT_EQ(j->getType(), eOperandType::TypeInt16);
    IOperand const *a = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *b = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *c = *v - *a;
    IOperand const *d = *b - *t;
    EXPECT_EQ(c->toString(), "0.000000");
    EXPECT_EQ(c->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(d->toString(), "0.000000");
    EXPECT_EQ(d->getType(), eOperandType::TypeFloat);
}

TEST(multiplication, combination)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt16, "5");
    IOperand const *s = *v * *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *t * *u;
    EXPECT_EQ(s->toString(), "25");
    EXPECT_EQ(s->getType(), eOperandType::TypeInt16);
    EXPECT_EQ(j->toString(), "0");
    EXPECT_EQ(j->getType(), eOperandType::TypeInt16);
    IOperand const *a = f.createOperand(eOperandType::TypeDouble, "5");
    IOperand const *b = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *c = *v * *a;
    IOperand const *d = *b * *t;
    EXPECT_EQ(c->toString(), "25.000000");
    EXPECT_EQ(c->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(d->toString(), "25.000000");
    EXPECT_EQ(d->getType(), eOperandType::TypeFloat);
}

TEST(division, combination)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt16, "5");
    IOperand const *s = *v / *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u / *t;
    EXPECT_EQ(s->toString(), "1");
    EXPECT_EQ(s->getType(), eOperandType::TypeInt16);
    EXPECT_EQ(j->toString(), "0");
    EXPECT_EQ(j->getType(), eOperandType::TypeInt16);
    IOperand const *a = f.createOperand(eOperandType::TypeDouble, "2");
    IOperand const *b = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *c = *v / *a;
    IOperand const *d = *b / *t;
    EXPECT_EQ(c->toString(), "2.500000");
    EXPECT_EQ(c->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(d->toString(), "1.000000");
    EXPECT_EQ(d->getType(), eOperandType::TypeFloat);
}

TEST(modulus, combination)
{
    Factory f;
    IOperand const *v = f.createOperand(eOperandType::TypeInt8, "5");
    IOperand const *t = f.createOperand(eOperandType::TypeInt16, "5");
    IOperand const *s = *v % *t;
    IOperand const *u = f.createOperand(eOperandType::TypeInt8, "0");
    IOperand const *j = *u % *t;
    EXPECT_EQ(s->toString(), "0");
    EXPECT_EQ(s->getType(), eOperandType::TypeInt16);
    EXPECT_EQ(j->toString(), "0");
    EXPECT_EQ(j->getType(), eOperandType::TypeInt16);
    IOperand const *a = f.createOperand(eOperandType::TypeDouble, "2");
    IOperand const *b = f.createOperand(eOperandType::TypeFloat, "5");
    IOperand const *c = *v % *a;
    IOperand const *d = *b % *t;
    EXPECT_EQ(c->toString(), "1.000000");
    EXPECT_EQ(c->getType(), eOperandType::TypeDouble);
    EXPECT_EQ(d->toString(), "0.000000");
    EXPECT_EQ(d->getType(), eOperandType::TypeFloat);
}
