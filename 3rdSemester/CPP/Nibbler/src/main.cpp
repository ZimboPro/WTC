#include <iostream>
#include "Loop.hpp"
#include "Snake.hpp"

bool isUnsignedDiscreteNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char **argv)
{
	if (argc != 3 || !isUnsignedDiscreteNumber(argv[1]) || !isUnsignedDiscreteNumber(argv[2]))
	{
		std::cout << "Usage:  ./nibbler [unsigned int representing height in pixels] [unsigned int representing width in pixels]" << std::endl;
		std::cout << "Min Height: " << MIN_HEIGHT;
		std::cout << " Max Height: " << MAX_HEIGHT;
		std::cout << " Min Width: " << MIN_WIDTH;
		std::cout << " Max Width: " << MAX_WIDTH << std::endl;
		return (1);
	}
	try {
		int height = std::stoi(argv[1]);
		int width = std::stoi(argv[2]);
		if (height > MAX_HEIGHT || width > MAX_WIDTH)
			throw Error::WindowMaxSizeError("One of the parameters exceeds the max width or height");
		if (height < MIN_HEIGHT || width < MIN_WIDTH)
			throw Error::WindowMinSizeError("One of the parameters is smaller than the minimum width or height");
		Loop loop(height, width);
		loop.GameLoop();

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
