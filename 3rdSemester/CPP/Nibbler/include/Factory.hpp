#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "IFunctions.hpp"

class Factory {
	public:
		Factory(unsigned int height = MAX_HEIGHT, unsigned int width = MAX_WIDTH);
		~Factory();
		Factory & operator=(const Factory &);
		Factory(const Factory &);
		IFunctions * createLibrary(int library);
		void deleteLibrary(IFunctions * graphicsLibrary);
		int getOpenLibrary();
	private:
		IFunctions * createSDL();
		IFunctions * createSFML();
		IFunctions * createOpenGL();
		unsigned int _width;
		unsigned int _height;
		int _openLibrary;
		void *_dlHandle;
		IFunctions * _graphicsInterface;
};

#endif
