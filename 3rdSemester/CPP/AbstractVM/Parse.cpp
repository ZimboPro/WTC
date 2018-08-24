/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06/19/11 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 06/19/11 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include <vector>
#include <sstream>
#include "Error.hpp"
#include "Logic.hpp"
#include <regex>

Parse::Parse() {}

Parse::Parse(Parse const & src)
{
	*this = src;	
}

Parse::~Parse() {}

Parse & Parse::operator=(Parse const & src)
{
	if (this != &src)
    {
		*this = src;
    }
	return (*this);
}

int Parse::countCommands(size_t *arr)
{
	int cnt = 0;
	if (arr[12] == std::string::npos)
	{
		for (int i = 0; i < 12; i++)
		{
			if (arr[i] != std::string::npos)
				cnt++;
		}
	}
	else
	{
		for (int i = 0; i < 12; i++)
		{
			if (arr[i] != std::string::npos && arr[i] < arr[12])
				cnt++;
		}
	}
	return cnt++;
}

size_t Parse::getComma(std::string const & command)
{
	size_t ans;
	if (command.find(";;") == std::string::npos)
		return command.find(";");
	else
	{
		ans = command.find(";");
		size_t t = command.find(";;");
		while (ans != std::string::npos && (ans == t || ans == t + 1))
		{
			ans = command.find(";", ans + 1);
		}
		return ans;
	}
}

void getType(eOperandType & type, std::string t)
{
	t = Logic::trim_copy(t);
	Logic::StrToUpper(t);
	if (t.compare("INT8") == 0)
		type = eOperandType::TypeInt8;
	else if (t.compare("INT16") == 0)
		type = eOperandType::TypeInt16;
	else if (t.compare("INT32") == 0)
		type = eOperandType::TypeInt32;
	else if (t.compare("FLOAT") == 0)
		type = eOperandType::TypeFloat;
	else if (t.compare("DOUBLE") == 0)
		type = eOperandType::TypeDouble;
	else
		throw Error::UnkownType();
}

void Parse::MultipleWord(std::string const & command, eOperandType & type, std::string & val)
{
	std::vector<std::string> words;
	std::string temp = command.substr(0, command.find(";"));
	temp = Logic::trim_copy(temp);
	std::regex form("(PUSH|ASSERT) (INT8|INT16|INT32|FLOAT|DOUBLE)\\s?\\(-?[[:digit:]]+(.?[[:digit:]]+)?\\)\\B");
	if (!std::regex_match(temp, form))
		throw Error::SyntaxError();
	std::istringstream ss( temp );
	while (!ss.eof())         // See the WARNING above for WHY we're doing this!
	{
		std::string x;               // here's a nice, empty string
		getline( ss, x, ' ' );  // try to read the next field into it
		words.push_back(x);
	}
	if (words.size() < 2 || words.size() > 3)
		throw Error::SyntaxError();
	size_t t;
	if (words.size() == 2)
	{
		t = words[1].find("(");
		getType(type, words[1].substr(0, t));
	}
	else
		getType(type, words[1]);
	
	if (words.size() == 2)
		val = words[1].substr(t);
	else
		val = words[2];
	
	val = Logic::trim_copy(val);
	val.erase(0, 1);
	val.erase(val.length() - 1, 1);
	if (val.length() == 0)
		throw Error::SyntaxError();
}

int Parse::Command(std::string const & command, eOperandType & type, std::string & val)
{
	size_t arr[13];
	std::string str[] = {";;", "PUSH", "POP", "ADD", "SUB", "MUL", "DIV", "MOD", "DUMP", "ASSERT", "PRINT", "EXIT"};
	std::string *temp = const_cast<std::string *>(&command);
	Logic::StrToUpper(*temp);

	arr[0] = temp->find(";;");
	arr[1] = temp->find("PUSH");
	arr[2] = temp->find("POP");
	arr[3] = temp->find("ADD");
	arr[4] = temp->find("SUB");
	arr[5] = temp->find("MUL");
	arr[6] = temp->find("DIV");
	arr[7] = temp->find("MOD");
	arr[8] = temp->find("DUMP");
	arr[9] = temp->find("ASSERT");
	arr[10] = temp->find("PRINT");
	arr[11] = temp->find("EXIT");
	arr[12] = getComma(*temp);
	int j = countCommands(arr);
	if (j == 1)
	{
		if (arr[12] != std::string::npos)
		{
			int i = 0;
			while (i < 12)
			{
				if (arr[i] != std::string::npos && arr[i] < arr[12])
					break;
				i++;
			}
			if (i == 12)
				return (-1);
			if (i == 0 || i == 11)
				return (0);
			else if (i == 1 || i == 9)
			{
				MultipleWord(command, type, val);
				return i;
			}
			else
				return (i);
		}
		else
		{
			int i = 0;
			while (i < 12 &&  arr[i] == std::string::npos)
				i++;
			if (i == 0 || i == 11)
				return (0);
			else if (i == 1 || i == 9)
			{
				MultipleWord(command, type, val);
				return i;
			}
			else
			{
				std::vector<std::string> words;
				std::string temp = command.substr(0, command.find(";"));
				temp = Logic::trim_copy(temp);
				std::istringstream ss( temp );
				while (!ss.eof())         // See the WARNING above for WHY we're doing this!
				{
					std::string x;               // here's a nice, empty string
					getline( ss, x, ' ' );  // try to read the next field into it
					words.push_back(x);
				}

				if (words.size() > 1)
					throw Error::SyntaxError();
				if (temp.compare(str[i]) != 0)
					throw Error::SyntaxError();
				return (i);
			}
		}
		MultipleWord(command, type, val);
	}
	else if (j > 1)
		throw Error::SyntaxError();
	else if (j == 0 && command.length() > 0 && (arr[12] == std::string::npos || arr[12] > 0))
		throw Error::Unkown();
	return (-1);
}
