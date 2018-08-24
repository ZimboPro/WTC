#include "Snake.hpp"
#include "IFunctions.hpp"

Snake::Snake() {}

Snake::Snake(int direction, int headY, int headX) 
{
	_body.push_back(new GameElement(headY, headX, HEAD));
	for (int i = 1; i < 4 && headX - i >= 0; i++)
	{
		_body.push_back(new GameElement(headY, headX - i, BODY));
	}
	this->_direction = direction;
	this->_score = 0;
}

std::list<GameElement *> * Snake::getSnakeBody() { return &this->_body; }

Snake::Snake(Snake const & src) {
	if (this != &src)
		*this = src;	
}

int Snake::getScore() { return this->_score; }

void Snake::setDirection(int newDirection) 
{
	if ((_direction == right && newDirection == left) ||
			(_direction == left && newDirection == right) ||
			(_direction == up && newDirection == down) ||
			(_direction == down && newDirection == up))
		return;
	this->_direction = newDirection; 
}

bool Snake::moveSnake(std::vector<std::vector<int8_t>> & map)
{
	GameElement * head = _body.front();
	GameElement * tail = _body.back();
	_body.pop_back();
	GameElement tmp;
	switch (_direction)
	{
		case up:
			if (head->getY() > 0 && map[head->getY() - 1][head->getX()] == NOTHING) {
				tail->setY(head->getY() - 1);
				tail->setX(head->getX());
				tail->setType(HEAD);
				head->setType(BODY);
				_body.push_front(tail);
				break;
			}
			else if (head->getY() > 0 && map[head->getY() - 1][head->getX()] == FOOD) {
				_body.push_front(new GameElement(head->getY() - 1, head->getX(), HEAD));
				_body.push_back(tail);
				head->setType(BODY);
				_score += 5;
				break; 
			}
			else
				return false;
		case down:
			if (head->getY() + 1 < static_cast<int>(map.size()) && map[head->getY() + 1][head->getX()] == NOTHING) {
				tail->setY(head->getY() + 1);
				tail->setX(head->getX());
				tail->setType(HEAD);
				head->setType(BODY);
				_body.push_front(tail);
				break; 
			}
			else if (head->getY() + 1 < static_cast<int>(map.size()) && map[head->getY() + 1][head->getX()] == FOOD) {
				_body.push_front(new GameElement(head->getY() + 1, head->getX(), HEAD));
				head->setType(BODY);
				_body.push_back(tail);
				_score += 5;
				break; 
			}
			else
				return false;
		case left:
			if (head->getX() > 0 && map[head->getY()][head->getX() - 1] == NOTHING) {
				tail->setY(head->getY());
				tail->setX(head->getX() - 1);
				tail->setType(HEAD);
				head->setType(BODY);
				_body.push_front(tail);
				break; 
			}
			else if (head->getX() > 0 && map[head->getY()][head->getX() - 1] == FOOD) {
				_body.push_front(new GameElement(head->getY(), head->getX() - 1, HEAD));
				_body.push_back(tail);
				head->setType(BODY);
				_score += 5;
				break; 
			}
			else
				return false;
		case right:
			if (head->getX() + 1 < static_cast<int>(map[0].size()) && map[head->getY()][head->getX() + 1] == NOTHING) {
				tail->setY(head->getY());
				tail->setX(head->getX() + 1);
				tail->setType(HEAD);
				head->setType(BODY);
				_body.push_front(tail);
				break; 
			}
			else if (head->getX() + 1 < static_cast<int>(map[0].size()) && map[head->getY()][head->getX() + 1] == FOOD) {
				_body.push_front(new GameElement(head->getY(), head->getX() + 1, BODY));
				_body.push_back(tail);
				head->setType(BODY);
				_score += 5;
				break; 
			}
			else
				return false;
	}
	return true;
}

Snake::~Snake() 
{
	std::list<GameElement *>::iterator it;
	for (it = _body.begin(); it != _body.end(); it++)
		delete *it;
	_body.clear();
}

Snake & Snake::operator=(Snake const &src)
{
	if (this != &src)
	{
		this->_body = src._body;
		this->_direction = src._direction;
		this->_score = src._score;
	}
	return *this;
}
