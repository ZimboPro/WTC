/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 08/24/37 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/20 10:01:29 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LOOP_HPP
# define	LOOP_HPP

#include "IFunctions.hpp"
#include <vector>
#include "Snake.hpp"


class Loop
{
	public:
		Loop(int height = MAX_HEIGHT, int width = MAX_WIDTH);
		Loop(Loop const & src);
		~Loop();
		Loop & operator=(Loop const & src);

		void GameLoop(void);
		void LibError(void);
		void LibError(std::string & s);
		
		void printMap();
		void placeSnake(Snake & snake);
		void clearLastPiece(Snake & snake);
		void placeFood();

	private:
		std::vector<std::vector<int8_t>> _map;
		int _mapHeight;
		int _mapWidth;
		int _winHeight;
		int _winWidth;
		GameElement _food;
};

#endif
