/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 06/50/59 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/20 09:37:19 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

Functions::Functions()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw Error::InitError();
}

Functions::Functions(Functions const & src)
{
	*this = src;	
}

Functions::~Functions()
{
	SDL_DestroyRenderer(this->_ren);
	SDL_DestroyWindow(this->_win);
	SDL_Quit();
}

Functions & Functions::operator=(Functions const & src)
{
	if (this != &src)
    {
		this->_win = src._win;
		this->_ren = src._ren;
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
	SDL_Rect rect;
	SDL_SetRenderDrawColor(this->_ren, 0,0,255,0);
	SDL_RenderClear(this->_ren);
	rect.h = BLOCK_SIZE;
	rect.w = BLOCK_SIZE;
	bool d;
	for (unsigned int c = 0; c < this->_cols; c++)
	{
		for (unsigned int r = 0; r < this->_rows; r++)
		{
			d = false;
			if (arr[r][c] == BODY)
			{
				SDL_SetRenderDrawColor(this->_ren, 0,255,0,0);
				d = true;
			}
			else if (arr[r][c] == HEAD)
			{
				SDL_SetRenderDrawColor(this->_ren, 255,0,0,0);
				d = true;
			}
			else if (arr[r][c] == FOOD)
			{
				SDL_SetRenderDrawColor(this->_ren, 0,255,255,0);
				d = true;
			}
			if (d)
			{
				rect.x = this->_le + BLOCK_SIZE * c;
				rect.y = this->_te + BLOCK_SIZE * r;
				SDL_RenderFillRect(this->_ren, &rect);
			}
		}
	}
	SDL_RenderPresent(this->_ren);
}

void Functions::Sleep(unsigned int sleep)
{
	SDL_Delay(sleep);
}

Keys Functions::Key()
{
	if (this->_event.type == SDL_KEYDOWN)
	{
		if (this->_event.key.keysym.sym == SDLK_ESCAPE)
			return Keys::Escape_Key;
		else if (this->_event.key.keysym.sym == SDLK_1)
			return Keys::Key_1;
		else if (this->_event.key.keysym.sym == SDLK_2)
			return Keys::Key_2;
		else if (this->_event.key.keysym.sym == SDLK_3)
			return Keys::Key_3;
		else if (this->_event.key.keysym.sym == SDLK_w)
			return Keys::W_Key;
		else if (this->_event.key.keysym.sym == SDLK_a)
			return Keys::A_Key;
		else if (this->_event.key.keysym.sym == SDLK_s)
			return Keys::S_Key;
		else if (this->_event.key.keysym.sym == SDLK_d)
			return Keys::D_Key;
		else if (this->_event.key.keysym.sym == SDLK_UP)
			return Keys::Up_Key;
		else if (this->_event.key.keysym.sym == SDLK_DOWN)
			return Keys::Down_Key;
		else if (this->_event.key.keysym.sym == SDLK_LEFT)
			return Keys::Left_Key;
		else if (this->_event.key.keysym.sym == SDLK_RIGHT)
			return Keys::Right_Key;
		else if (this->_event.key.keysym.sym == SDLK_SPACE)
			return Keys::SpaceBar;
		else if (this->_event.key.keysym.sym == SDLK_RETURN)
			return Keys::Enter_Key;
		else
			return Keys::Wrong_Key;
	}
	else
		return (Keys::No_Key_Pressed);
}

bool Functions::Event()
{
	if (SDL_PollEvent(&this->_event) == 1)
		return true;
	else
		return false;
}

bool Functions::CloseWindow()
{
	if (this->_event.type == SDL_QUIT)
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
	if (SDL_CreateWindowAndRenderer(w, h,0, &this->_win, &this->_ren) == -1)
		throw Error::CreateWindowError();

	SDL_SetWindowTitle(this->_win, "Nibbler SDL");
	SDL_SetWindowPosition(this->_win, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);

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
}

void Functions::Color(uint8_t r, uint8_t g, uint8_t b)
{
	SDL_SetRenderDrawColor(this->_ren, 0,0,0,0);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = this->_h;
	rect.w = this->_w;
	
	SDL_RenderClear(this->_ren);
	SDL_SetRenderDrawColor(this->_ren, r,g,b,0);
	SDL_RenderFillRect(this->_ren, &rect);
	SDL_RenderPresent(this->_ren);
}

Functions * createFunctions()
{
	return new Functions();
}

void deleteFunctions(Functions * func)
{
	delete func;
}
