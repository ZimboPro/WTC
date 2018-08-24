/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 08/24/37 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/24 08:38:13 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <vector>
#include "Loop.hpp"
#include "Factory.hpp"

void Loop::GameLoop(void)
{
	Snake snake(right, _mapHeight / 2, _mapWidth / 2);
	Factory factory(_winHeight, _winWidth);
	int sleep = 80;
	int runningScore;
	int level = 1;
	try
	{
		IFunctions *func = factory.createLibrary(SDL);
		while (snake.moveSnake(_map))
		{
			placeSnake(snake);
			if (func->Event())
			{
				if (func->CloseWindow())
					break;
				else if (func->Key() == Escape_Key)
					break;
				else if (func->Key() == Key_1 || func->Key() == Key_2 || func->Key() == Key_3)
					func = factory.createLibrary(func->Key());
				else if (func->Key() == Up_Key || func->Key() == Down_Key || func->Key() == Left_Key || func->Key() == Right_Key)
					snake.setDirection(func->Key());
			}
			if (runningScore != snake.getScore() && snake.getScore() != 0 && sleep > 20 && snake.getScore() % 20  == 0) {
				runningScore = snake.getScore();
				sleep -= 10;
				level++;
				std::cout << "You have now reached level: " << level << std::endl;
			} 
			func->Render(_map);
			func->Sleep(sleep);
			clearLastPiece(snake);
		}
		factory.deleteLibrary(func);
		std::cout << "Total Score: " << snake.getScore() << ", Level Reached " << level << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Loop::Loop(int height, int width)
{
	this->_winHeight = height;
	this->_winWidth = width;
	this->_mapHeight = height/BLOCK_SIZE;
	this->_mapWidth= width/BLOCK_SIZE;
	for (int i = 0; i < _mapHeight; i++)
	{
		std::vector<int8_t> temp;
		this->_map.push_back(temp);
	}

	for (int i = 0; i < this->_mapHeight; i++)
		for (int j = 0; j < this->_mapWidth; j++)
			this->_map[i].push_back(NOTHING);

	placeFood();
}

Loop::Loop(Loop const &src)
{
	if (this != &src)
	{
	*this = src;
	}
}

Loop::~Loop()
{
	for (int i = 0; i < this->_mapHeight; i++)
		this->_map[i].clear();
	this->_map.clear();
}

Loop &Loop::operator=(Loop const &src)
{
	if (this != &src)
	{
		this->_map = src._map;
		this->_mapHeight = src._mapHeight;
		this->_mapWidth = src._mapWidth;
		this->_winHeight = src._winHeight;
		this->_winWidth = src._winWidth;
		this->_food = src._food;
	}
	return (*this);
}

void Loop::placeFood()
{
	srand(time(NULL));
	int foodY = rand() % _mapHeight;
	int foodX = rand() % _mapWidth;
	while(_map[foodY][foodX] != NOTHING) 
	{
		srand(time(NULL));
		foodY = rand() % _mapHeight;
		foodX = rand() % _mapWidth;
	}
	_food.setY(foodY);
	_food.setY(foodX);
	_food.setType(FOOD);

	_map[foodY][foodX] = FOOD;
}


void Loop::LibError(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void Loop::LibError(std::string & s)
{
	std::cerr << "Error: " << s << std::endl;
	exit(EXIT_FAILURE);
}

void Loop::placeSnake(Snake & snake)
{
	std::list<GameElement *>::iterator it;
	for (it = snake.getSnakeBody()->begin(); it != snake.getSnakeBody()->end(); it++)
	{
		if (this->_map[(*it)->getY()][(*it)->getX()] == FOOD)
			placeFood();

		this->_map[(*it)->getY()][(*it)->getX()] = (*it)->getType();
	}
}

void Loop::clearLastPiece(Snake & snake)
{
	GameElement * last = snake.getSnakeBody()->back();
	this->_map[last->getY()][last->getX()] = NOTHING;
}

void Loop::printMap()
{
	for (size_t y = 0; y < _map.size(); y++)
	{
		for (size_t x = 0; x < _map[y].size(); x++)
			std::cout << static_cast<int>(_map[y][x]);
		std::cout << std::endl;
	}
}
