/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07/12/08 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/03 07/12/08 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>

Functions::Functions()
{
	if (!glfwInit())
		throw Error::InitError();
	
	this->_key = Keys::Wrong_Key;
}

Functions::Functions(Functions const & src)
{
	*this = src;	
}

Functions::~Functions()
{
	//glfwDestroyWindow(this->_win);
	glfwTerminate();
}

Functions & Functions::operator=(Functions const & src)
{
	if (this != &src)
    {
		this->_win = src._win;
		this->_key = src._key;
		this->_w = src._w;
		this->_h = src._h;
		this->_le = src._le;
		this->_re = src._re;
		this->_be = src._be;
		this->_te = src._te;
		this->_rows = src._rows;
		this->_cols = src._cols;
    }
	return (*this);
}

void Functions::draw(int x, int y, int r, int g, int b)
{
	glColor3f(static_cast<float>(r) / 255, static_cast<float>(g) / 255, static_cast<float>(b) / 255);
	float xf = static_cast<float>(x - static_cast<int>(this->_w >> 1)) / static_cast<float>(this->_w >> 1);
	float yf = static_cast<float>(static_cast<int>(this->_h >> 1) - y) / static_cast<float>(this->_h >> 1);
	float xf1 = static_cast<float>(x + BLOCK_SIZE - static_cast<int>(this->_w >> 1)) / static_cast<float>(this->_w >> 1);
	float yf1 = static_cast<float>(static_cast<int>(this->_h >> 1) - y - BLOCK_SIZE) / static_cast<float>(this->_h >> 1);

	glBegin(GL_TRIANGLES);
	glVertex2f(xf, yf);
	glVertex2f(xf1, yf);
	glVertex2f(xf, yf1);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(xf1, yf);
	glVertex2f(xf, yf1);
	glVertex2f(xf1, yf1);
	glEnd();
}

void Functions::Render(std::vector<std::vector<int8_t>> & arr)
{
	int w;
	int h;
	glfwGetFramebufferSize(this->_win, &w, &h);
	glViewport(0, 0, w, h);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	for (unsigned int c = 0; c < this->_cols; c++)
	{
		for (unsigned int r = 0; r < this->_rows; r++)
		{
			if (arr[r][c] == BODY)
			{
				draw(this->_le + BLOCK_SIZE * c, this->_te + BLOCK_SIZE * r, 255, 0, 0);
			}
			else if (arr[r][c] == HEAD)
			{
				draw(this->_le + BLOCK_SIZE * c, this->_te + BLOCK_SIZE * r, 0, 255, 0);
			}
			else if (arr[r][c] == FOOD)
			{
				draw(this->_le + BLOCK_SIZE * c, this->_te + BLOCK_SIZE * r, 0, 0, 255);
			}
		}
	}
	glfwSwapBuffers(this->_win);
    glfwPollEvents();
}

void Functions::Sleep(unsigned int sleep)
{
	usleep(sleep * 1000);
}

Keys Functions::Key()
{
	return (this->_key);
}

Keys Functions::getKey()
{
	if (glfwGetKey(this->_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->_win, true);
		return Keys::Escape_Key;
	}
	else if (glfwGetKey(this->_win, GLFW_KEY_UP) == GLFW_PRESS)
		return Keys::Up_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_DOWN) == GLFW_PRESS)
		return Keys::Down_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_LEFT) == GLFW_PRESS)
		return Keys::Left_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		return Keys::Right_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_W) == GLFW_PRESS)
		return Keys::W_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_A) == GLFW_PRESS)
		return Keys::A_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_S) == GLFW_PRESS)
		return Keys::S_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_D) == GLFW_PRESS)
		return Keys::D_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_SPACE) == GLFW_PRESS)
		return Keys::SpaceBar;
	else if (glfwGetKey(this->_win, GLFW_KEY_ENTER) == GLFW_PRESS)
		return Keys::Enter_Key;
	else if (glfwGetKey(this->_win, GLFW_KEY_1) == GLFW_PRESS)
		return Keys::Key_1;
	else if (glfwGetKey(this->_win, GLFW_KEY_2) == GLFW_PRESS)
		return Keys::Key_2;
	else if (glfwGetKey(this->_win, GLFW_KEY_3) == GLFW_PRESS)
		return Keys::Key_3;
	else
		return Keys::Wrong_Key;
}

bool Functions::Event()
{
	glfwPollEvents();
	this->_key = getKey();
	if (this->_key != Keys::Wrong_Key || glfwWindowShouldClose(this->_win))
		return (true);
	else
		return (false);
}

bool Functions::CloseWindow()
{
	if (glfwWindowShouldClose(this->_win))
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
	this->_win = glfwCreateWindow(w, h, "Nibbler OpenGL (GLFW)", glfwGetPrimaryMonitor(), NULL);
	if (!this->_win)
		throw Error::CreateWindowError();
	
	glfwMakeContextCurrent(this->_win);

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
	int w;
	int h;
	glfwGetFramebufferSize(this->_win, &w, &h);
	glViewport(0, 0, w, h);

	float rf = static_cast<float>(r) / 255.0f;
	float gf = static_cast<float>(g) / 255.0f;
	float bf = static_cast<float>(b) / 255.0f;
	
    glClearColor(rf, gf, bf, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(this->_win);
    glfwPollEvents();
}

Functions * createFunctions()
{
	return new Functions();
}

void deleteFunctions(Functions * func)
{
	delete func;
}