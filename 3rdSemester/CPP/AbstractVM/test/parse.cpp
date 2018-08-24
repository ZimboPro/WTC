/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:28:41 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 09:28:43 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"
#include "../Parse.hpp"

TEST(multi_word, parse)
{
    Parse p;
    eOperandType type;
    std::string val;
    p.MultipleWord("PUSH INT8(32)", type, val);
    EXPECT_EQ(type, eOperandType::TypeInt8);
    EXPECT_EQ(val, "32");
    p.MultipleWord("PUSH INT16(62)", type, val);
    EXPECT_EQ(val, "62");
    EXPECT_EQ(type, eOperandType::TypeInt16);
    p.MultipleWord("PUSH FLOAT(3.6)", type, val);
    EXPECT_EQ(val, "3.6");
    EXPECT_EQ(type, eOperandType::TypeFloat);
    p.MultipleWord("ASSERT DOUBLE(-17.65)", type, val);
    EXPECT_EQ(type, eOperandType::TypeDouble);
    EXPECT_EQ(val, "-17.65");
}

TEST(errors, parse)
{
    Parse p;
    eOperandType type;
    std::string val;
    EXPECT_THROW(p.MultipleWord("PUSH int18(32)", type, val), Error::SyntaxError);
    EXPECT_THROW(p.MultipleWord("PUSH INT8(32", type, val), Error::SyntaxError);
    EXPECT_THROW(p.MultipleWord("PUSH INT832)", type, val), Error::SyntaxError);
    EXPECT_NO_THROW(p.MultipleWord("ASSERT INT8 (32)", type, val));
    EXPECT_THROW(p.MultipleWord("ADD INT8 (32)", type, val), Error::SyntaxError);
    EXPECT_THROW(p.MultipleWord("PUSH INT8()", type, val), Error::SyntaxError);
}

TEST(command, parse)
{
    Parse p;
    eOperandType type;
    std::string val;
    EXPECT_EQ(p.Command("push int8(32)", type, val), 1);
    EXPECT_EQ(type, eOperandType::TypeInt8);
    EXPECT_EQ(val, "32");

    EXPECT_EQ(p.Command("push int16(62)", type, val), 1);
    EXPECT_EQ(val, "62");
    EXPECT_EQ(type, eOperandType::TypeInt16);

    EXPECT_EQ(p.Command("push float(3.6)", type, val), 1);
    EXPECT_EQ(val, "3.6");
    EXPECT_EQ(type, eOperandType::TypeFloat);

    EXPECT_EQ(p.Command("assert double(-17.65)", type, val), 9);
    EXPECT_EQ(type, eOperandType::TypeDouble);
    EXPECT_EQ(val, "-17.65");

    EXPECT_EQ(p.Command(";;", type, val), 0);
    EXPECT_EQ(p.Command("; ;;", type, val), -1);
    EXPECT_EQ(p.Command("add; ;;", type, val), 3);
    EXPECT_THROW(p.Command("add ;;", type, val), Error::SyntaxError);
}
