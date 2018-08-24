/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06/19/47 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 06/19/47 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LOGIC_HPP
# define	LOGIC_HPP

#include <iostream>
#include <vector>
#include "Operand.hpp"
#include "Factory.hpp"

class Logic {
	public:
		Logic();
		Logic(Logic const & src);
		~Logic();
		Logic & operator=(Logic const & src);

		void ReadLoop();
		void FileLoop(std::string const & str);
		void Print();
		void Dump();
		void Assert(eOperandType type, std::string const & value);
		void Pop();
		void Push(eOperandType type, std::string const & value);
		void Calc(int i);
		static std::string trim_copy(const std::string &s, const std::string &delimiters = " \f\n\r\t\v");
		static void StrToUpper(std::string &str);
		bool ParseString(std::string &command);

	private:
		std::vector<IOperand const *> _stack;
		Factory _f;
};

#endif
