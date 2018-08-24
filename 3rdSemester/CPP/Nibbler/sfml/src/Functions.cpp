/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11/21/35 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/02 11/21/35 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

Functions::Functions() {}

Functions::Functions(Functions const & src)
{
	*this = src;	
}

Functions::~Functions()
{
	this->_win->close();
	delete this->_win;
}

Functions & Functions::operator=(Functions const & src)
{
	if (this != &src)
    {
		this->_win = src._win;
		this->_w = src._w;
		this->_h = src._h;
		this->_le = src._le;
		this->_re = src._re;
		this->_be = src._be;
		this->_te = src._te;
		this->_rows = src._rows;
		this->_cols = src._cols;
		this->_event = src._event;
    }
	return (*this);
}

void Functions::Render(std::vector<std::vector<int8_t>> & arr)
{
	sf::Color col;
	col.r = 120;
	col.g = 0;
	col.b = 0;
	this->_win->clear(col);
	sf::RectangleShape rect(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	bool d;
	
	for (unsigned int c = 0; c < this->_cols; c++)
	{
		for (unsigned int r = 0; r < this->_rows; r++)
		{
			d = false;
			if (arr[r][c] == BODY)
			{
				col.r = 0;
				col.g = 255;
				col.b = 0;
				d = true;
			}
			else if (arr[r][c] == HEAD)
			{
				col.r = 0;
				col.g = 0;
				col.b = 255;
				d = true;
			}
			else if (arr[r][c] == FOOD)
			{
				col.r = 255;
				col.g = 0;
				col.b = 255;
				d = true;
			}
			if(d)
			{
				rect.setPosition(static_cast<float>(this->_le + BLOCK_SIZE * c), static_cast<float>(this->_te + BLOCK_SIZE * r));
				rect.setFillColor(col);
				this->_win->draw(rect);
			}
			
		}
	}
	this->_win->display();
}

void Functions::Sleep(unsigned int sleep)
{
	sf::Time delay = sf::milliseconds(sleep);
	sf::sleep(delay);
}

Keys Functions::Key()
{
	if (this->_event.type == sf::Event::KeyPressed)
	{
		if (this->_event.key.code == sf::Keyboard::Escape)
			return Keys::Escape_Key;
		else if (this->_event.key.code == sf::Keyboard::Num1)
			return Keys::Key_1;
		else if (this->_event.key.code == sf::Keyboard::Num2)
			return Keys::Key_2;
		else if (this->_event.key.code == sf::Keyboard::Num3)
			return Keys::Key_3;
		else if (this->_event.key.code == sf::Keyboard::W)
			return Keys::W_Key;
		else if (this->_event.key.code == sf::Keyboard::A)
			return Keys::A_Key;
		else if (this->_event.key.code == sf::Keyboard::S)
			return Keys::S_Key;
		else if (this->_event.key.code == sf::Keyboard::D)
			return Keys::D_Key;
		else if (this->_event.key.code == sf::Keyboard::Up)
			return Keys::Up_Key;
		else if (this->_event.key.code == sf::Keyboard::Down)
			return Keys::Down_Key;
		else if (this->_event.key.code == sf::Keyboard::Left)
			return Keys::Left_Key;
		else if (this->_event.key.code == sf::Keyboard::Right)
			return Keys::Right_Key;
		else if (this->_event.key.code == sf::Keyboard::Space)
			return Keys::SpaceBar;
		else if (this->_event.key.code == sf::Keyboard::Return)
			return Keys::Enter_Key;
		else
			return Keys::Wrong_Key;
	}
	else
		return (Keys::No_Key_Pressed);
}

bool Functions::Event()
{
	return (this->_win->pollEvent(this->_event));
}

bool Functions::CloseWindow()
{
	if (this->_event.type == sf::Event::Closed)
		return true;
	else
		return false;
}

void Functions::Initialise(unsigned int w, unsigned int h)
{
	if (w > MAX_WIDTH || h > MAX_HEIGHT)
		throw Error::WindowMaxSizeError();
	if (w < MIN_WIDTH || h < MIN_WIDTH)
		throw Error::WindowMinSizeError();
	sf::String s;
	s = "Nibbler SFML";
	this->_win =  new sf::RenderWindow(sf::VideoMode(w, h),  s, sf::Style::None);
	if (this->_win == NULL)
		throw Error::CreateWindowError();
	this->_w = w;
	this->_h = h;
	this->_rows = this->_h / BLOCK_SIZE;
	this->_cols = this->_w / BLOCK_SIZE;
	if (this->_w % BLOCK_SIZE != 0)
	{
		this->_le = (this->_w % BLOCK_SIZE) > 1;
		this->_re = this->_w % BLOCK_SIZE - this->_le;
	}
	else
	{
		this->_le = 0;
		this->_re = 0;
	}
	if (this->_h % BLOCK_SIZE != 0)
	{
		this->_te = (this->_h % BLOCK_SIZE) > 1;
		this->_be = this->_h % BLOCK_SIZE - this->_te;
	}
	else
	{
		this->_te = 0;
		this->_be = 0;
	}
	this->_win->setActive(false);
}

void Functions::Color(uint8_t r, uint8_t g, uint8_t b)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(this->_w, this->_h));
	rect.setPosition(0, 0);

	sf::Color col(r, g, b);

	rect.setFillColor(col);
	this->_win->setActive();
	this->_win->draw(rect);
	this->_win->display();
}

Functions * createFunctions()
{
	return new Functions();
}

void deleteFunctions(Functions * func)
{
	delete func;
}