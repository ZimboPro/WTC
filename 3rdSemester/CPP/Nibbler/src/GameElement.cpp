#include "GameElement.hpp"

GameElement::GameElement() {}

GameElement::GameElement(int y, int x, int type) 
{
	this->_y = y;
	this->_x = x;
	this->_type = type;
}

GameElement::GameElement(GameElement const & src) 
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_x = src._x;
		this->_y = src._y;
	}
}

GameElement::~GameElement() {}

GameElement & GameElement::operator=(GameElement const & src) 
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_x = src._x;
		this->_y = src._y;
	}	
	return *this;
}

bool GameElement::operator==(GameElement const & rhs)
{
	if (this->_type == rhs._type && this->_x == rhs._x && this->_y == rhs._y)
		return true;
	return false;
}

int GameElement::getX() { return this->_x; }
int GameElement::getY() { return this->_y; }
int GameElement::getType() { return this->_type; }

void GameElement::setX(int x) { this->_x = x; }
void GameElement::setY(int y) { this->_y = y; }
void GameElement::setType(int type) { this->_type = type; }

