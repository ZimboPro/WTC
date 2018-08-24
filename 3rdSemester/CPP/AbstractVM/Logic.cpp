/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06/19/47 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 06/19/47 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logic.hpp"
#include <string>
#include <fstream>
#include "Parse.hpp"
#include "Error.hpp"

Logic::Logic() {}

Logic::Logic(Logic const &src)
{
	*this = src;
}

Logic::~Logic()
{
	for (size_t i = 0; i < this->_stack.size(); i++)
	{
		delete this->_stack[i];
	}
	this->_stack.clear();
}

Logic &Logic::operator=(Logic const &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
	}
	return (*this);
}

void Logic::StrToUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}

inline std::string trim_right_copy(const std::string &s, const std::string &delimiters = " \f\n\r\t\v")
{
	return s.substr(0, s.find_last_not_of(delimiters) + 1);
}

inline std::string trim_left_copy(const std::string &s, const std::string &delimiters = " \f\n\r\t\v")
{
	return s.substr(s.find_first_not_of(delimiters));
}

std::string Logic::trim_copy(const std::string &s, const std::string &delimiters)
{
	return trim_left_copy(trim_right_copy(s, delimiters), delimiters);
}

bool Logic::ParseString(std::string &command)
{
	try
	{
		eOperandType type;
		std::string val;
		int comm = Parse::Command(command, type, val);
		if (comm == 0)
			return false;
		switch (comm)
		{
			case (1):
				Push(type, val);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Calc(0);
				break;
			case 4:
				Calc(1);
				break;
			case 5:
				Calc(2);
				break;
			case 6:
				Calc(3);
				break;
			case 7:
				Calc(4);
				break;
			case 8:
				Dump();
				break;
			case 9:
				Assert(type, val);
				break;
			case 10:
				Print();
				break;
		}
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << command << std::endl << e.what() << std::endl << std::endl;
	}
	return true;
}

void Logic::ReadLoop()
{
	std::string command;
	while (true)
	{
		std::getline(std::cin, command);
		if (command.length() > 0)
		{
			command = trim_copy(command);
			StrToUpper(command);
			if (command.length() > 0)
			{
				if (!ParseString(command))
					break;
			}
			command.clear();
		}
	}
}

bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
	if(mainStr.size() >= toMatch.size() &&
			mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
			return true;
		else
			return false;
}

void Logic::FileLoop(std::string const &str)
{
	try
	{
		if (!endsWith(str, ".avm"))
			throw Error::FileType();
		std::ifstream file(str);
		std::string command;
		bool check = true;
		while (std::getline(file, command))
		{
			if (command.length() > 0)
			{
				command = trim_copy(command);
				StrToUpper(command);
				if (command.length() > 0)
				{
					if (!ParseString(command))
					{
						check = false;
						break;
					}
				}
				command.clear();
			}
		}
		if (check)
			throw Error::NoExit();
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}
}

void Logic::Print()
{
	if (this->_stack.size() != 0)
	{
		if (this->_stack[this->_stack.size() - 1]->getType() == eOperandType::TypeInt8)
		{
			int i = std::stoi(this->_stack[this->_stack.size() - 1]->toString());
			std::cout << static_cast<char>(i) << std::endl;
		}
		else
			throw Error::InvalidType();
	}
	else
		throw Error::EmptyStack();
}

void Logic::Dump()
{
	if (this->_stack.size() != 0)
	{
		for (int i = static_cast<int>(this->_stack.size() - 1); i >= 0; i--)
		{
			std::cout << this->_stack[i]->toString() << std::endl;
		}
	}
	else
		throw Error::EmptyStack();
}

void Logic::Assert(eOperandType type, std::string const &value)
{
	if (this->_stack.size() != 0)
	{
		IOperand const *a = this->_f.createOperand(type, value);
		if (a->getType() != this->_stack[this->_stack.size() - 1]->getType())
		{
			delete a;
			throw Error::InvalidType();
		}
		else if (a->toString().compare(this->_stack[this->_stack.size() - 1]->toString()) != 0)
		{
			delete a;
			throw Error::AssertNotTrue();
		}
	}
	else
		throw Error::EmptyStack();
}

void Logic::Pop()
{
	if (this->_stack.size() != 0)
	{
		delete this->_stack[this->_stack.size() - 1];
		this->_stack.pop_back();
	}
	else
		throw Error::EmptyStack();
}

void Logic::Push(eOperandType type, std::string const &value)
{
	this->_stack.push_back(this->_f.createOperand(type, value));
}

void Logic::Calc(int i)
{
	if (this->_stack.size() > 1)
	{
		IOperand const *a = this->_stack[this->_stack.size() - 1];
		IOperand const *b = this->_stack[this->_stack.size() - 2];
		if (i == 0)
		{
			IOperand const * ans = *a + *b;
			this->_stack.pop_back();
			this->_stack.pop_back();
			this->_stack.push_back(this->_f.createOperand(ans->getType(), ans->toString()));
			delete ans;
		}
		else if (i == 1)
		{
			IOperand const * ans = *a - *b;
			this->_stack.pop_back();
			this->_stack.pop_back();
			this->_stack.push_back(this->_f.createOperand(ans->getType(), ans->toString()));
			delete ans;
		}
		else if (i == 2)
		{
			IOperand const * ans = *a * *b;
			this->_stack.pop_back();
			this->_stack.pop_back();
			this->_stack.push_back(this->_f.createOperand(ans->getType(), ans->toString()));
			delete ans;
		}
		else if (i == 3)
		{
			IOperand const * ans = *a / *b;
			this->_stack.pop_back();
			this->_stack.pop_back();
			this->_stack.push_back(this->_f.createOperand(ans->getType(), ans->toString()));
			delete ans;
		}
		else if (i == 4)
		{
			IOperand const * ans = *a % *b;
			this->_stack.pop_back();
			this->_stack.pop_back();
			this->_stack.push_back(this->_f.createOperand(ans->getType(), ans->toString()));
			delete ans;
		}
		
		delete a;
		delete b;
	}
	else if (this->_stack.size() == 1)
		throw Error::OneElement();
	else
		throw Error::EmptyStack();
}
