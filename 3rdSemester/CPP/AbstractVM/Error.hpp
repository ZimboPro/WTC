/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 07:34:35 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/22 07:34:37 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

#include <exception>

class Error
{
    public:
        class OverFlow : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Overflow for number";
            }
        };
        class UnderFlow : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Underflow for number";
            }
        };
        class DivBy0 : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Dividing by 0";
            }
        };
        class ModBy0 : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Modulus of 0";
            }
        };
        class EmptyStack : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Stack is empty";
            }
        };
        class AssertNotTrue : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Does not equal value";
            }
        };
        class OneElement : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Only one element on the stack";
            }
        };
        class Unkown : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Unknown command";
            }
        };
        class UnkownType : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Unknown type";
            }
        };
        class NoExit : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: No exit instruction";
            }
        };
        class SyntaxError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Syntax error";
            }
        };
        class LexicalError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Lexical error";
            }
        };
        class InvalidType : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Wrong type";
            }
        };
        class FileType : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Wrong file type";
            }
        };
};

#endif
