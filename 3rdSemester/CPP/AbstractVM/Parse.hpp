/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06/19/11 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/27 06/19/11 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PARSE_HPP
# define	PARSE_HPP

#include <iostream>
#include "eOperandType.hpp"

class Parse {
	public:
		Parse();
		Parse(Parse const & src);
		~Parse();
		Parse & operator=(Parse const & src);

		static int Command(std::string const & command, eOperandType & type, std::string & val);
		static void MultipleWord(std::string const & command, eOperandType & type, std::string & val);
		static size_t getComma(std::string const & command);
		static int countCommands(size_t *arr);
	private:

	protected:

};

#endif
