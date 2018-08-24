/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 08:22:08 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/21 08:22:09 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.hpp"
#include "Factory.hpp"
#include "Logic.hpp"

int main(int ac, char **av)
{
    Logic l;
    if (ac == 1)
    {
        l.ReadLoop();
    }
    else if (ac == 2)
    {
        l.FileLoop(static_cast<std::string>(av[1]));
    }
    else
        std::cout << "Usage ./avm file.avm OR ./avm\n";
    return (0);
}
