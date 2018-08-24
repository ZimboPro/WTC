/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:38:33 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/22 09:38:36 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gtest/gtest.h"
#include "../Operand.hpp"
#include "../Factory.hpp"

int main(int ac, char** argv)
{
    testing::InitGoogleTest(&ac, argv);
    return RUN_ALL_TESTS();
}

#include "int8.cpp"
#include "int16.cpp"
#include "int32.cpp"
#include "float.cpp"
#include "double.cpp"
#include "combination.cpp"
#include "errors.cpp"
#include "parse.cpp"
#include "logic.cpp"
#include "read.cpp"
