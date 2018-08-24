/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11/21/35 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/02 11/21/35 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FUNCTIONS_HPP
# define	FUNCTIONS_HPP

#include "../../include/IFunctions.hpp"
#include <SFML/Graphics.hpp>

class Functions : public IFunctions
{
	public:
		Functions();
		Functions(Functions const & src);
		virtual ~Functions();
		Functions & operator=(Functions const & src);

		virtual void Render(std::vector<std::vector<int8_t>> & arr);
		virtual void Sleep(unsigned int sleep);
		virtual Keys Key();
        virtual bool Event();
        virtual bool CloseWindow();
        virtual void Initialise(unsigned int w, unsigned int h);
		virtual void Color(uint8_t r, uint8_t g, uint8_t b);
	private:
		sf::RenderWindow *_win;
		sf::Event _event;
		unsigned int _w;
		unsigned int _h;
		unsigned int _le;
		unsigned int _re;
		unsigned int _be;
		unsigned int _te;
		unsigned int _rows;
		unsigned int _cols;
	protected:

};

extern "C" Functions * createFunctions();
extern "C" void deleteFunctions(Functions * func);

#endif
