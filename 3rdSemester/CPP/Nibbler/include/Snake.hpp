#ifndef		SNAKE_HPP
# define	SNAKE_HPP

#include <list>
#include "GameElement.hpp"
#include "eSnake.hpp"

class Snake {
	public:
		Snake();
		Snake(int direction, int headY, int headX);
		Snake(Snake const & src);
		~Snake();
		Snake & operator=(Snake const &src);
		std::list<GameElement *> * getSnakeBody();
		bool moveSnake(std::vector<std::vector<int8_t>> & map);
		void setDirection(int newDirection);
		void eat();
		int getScore();
	private:
		std::list<GameElement *> _body;
		int _direction;
		int _score;
};

#endif
