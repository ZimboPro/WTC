/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07/12/08 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/03 07/12/08 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FUNCTIONS_HPP
# define	FUNCTIONS_HPP

#include "../../include/IFunctions.hpp"
#include <GLFW/glfw3.h>

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
		GLFWwindow* _win;
		Keys _key;
		unsigned int _w;
		unsigned int _h;
		unsigned int _le;
		unsigned int _re;
		unsigned int _be;
		unsigned int _te;
		unsigned int _rows;
		unsigned int _cols;
		Keys getKey();
		void draw(int x, int y, int r, int g, int b);

};

extern "C" Functions * createFunctions();
extern "C" void deleteFunctions(Functions * func);

#endif