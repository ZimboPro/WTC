#include <dlfcn.h>
#include "eLib.hpp"
#include "Factory.hpp"
#include "ErrorRefactor.hpp"

Factory::~Factory()
{
	if (_openLibrary)
		deleteLibrary(_graphicsInterface);
}

Factory::Factory(unsigned int height, unsigned int width) {
	_width = width;
	_height = height;
	_openLibrary = SDL;
	createSDL();
}

IFunctions *Factory::createLibrary(int library)
{
	if (library == _openLibrary)
		return (_graphicsInterface);
	else
		deleteLibrary(_graphicsInterface);

	switch(library) {
		case SDL:
			return createSDL();
			break;
		case SFML:
			return createSFML();
			break;
		case OPENGL:
			return createOpenGL();
			break;
		default:
			return NULL;
			break;
	}
}

void Factory::deleteLibrary(IFunctions * graphicsInterface)
{
	if (!_dlHandle) throw Error::NoDLOpen();

	void  (*destroy)(IFunctions *);
	destroy = (void(*)(IFunctions *))dlsym(_dlHandle, "deleteFunctions");
	if (!destroy) throw Error::DLError(dlerror());

	destroy(graphicsInterface);
	dlclose(_dlHandle);
	_dlHandle = NULL;
	_openLibrary = 0;
	_graphicsInterface = NULL;
}

IFunctions *Factory::createSDL()
{
	_dlHandle = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
	if (!_dlHandle) throw Error::DLError(dlerror());

	_openLibrary = SDL;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)()) dlsym(_dlHandle, "createFunctions");
	if (!create) throw Error::DLError(dlerror());

	this->_graphicsInterface = create();
	this->_graphicsInterface->Initialise(_width, _height);
	return this->_graphicsInterface;
}

IFunctions *Factory::createSFML()
{
	_dlHandle = dlopen("sfml/libsfml.dylib", RTLD_LAZY);
	if (!_dlHandle) throw Error::DLError(dlerror());

	_openLibrary = SFML;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)()) dlsym(_dlHandle, "createFunctions");
	if (!create) throw Error::DLError(dlerror());

	this->_graphicsInterface = create();
	this->_graphicsInterface->Initialise(_width, _height);
	return this->_graphicsInterface;
}

IFunctions *Factory::createOpenGL()
{
	_dlHandle = dlopen("opengl/libog.dylib", RTLD_LAZY);
	if (!_dlHandle) throw Error::DLError(dlerror());

	_openLibrary = OPENGL;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)()) dlsym(_dlHandle, "createFunctions");
	if (!create) throw Error::DLError(dlerror());

	this->_graphicsInterface = create();
	this->_graphicsInterface->Initialise(_width, _height);
	return this->_graphicsInterface;
}

int Factory::getOpenLibrary() { return this->_openLibrary; }

Factory & Factory::operator=(const Factory & rhs)
{
	if (this != &rhs)
	{
		this->_width = rhs._width;
		this->_height = rhs._height;
		this->_openLibrary = rhs._openLibrary;
		this->_dlHandle = rhs._dlHandle;
		this->_graphicsInterface = rhs._graphicsInterface;
	}
	return *this;
}

Factory::Factory(const Factory & rhs)
{
	if (this != &rhs)
	{
		this->_width = rhs._width;
		this->_height = rhs._height;
		this->_openLibrary = rhs._openLibrary;
		this->_dlHandle = rhs._dlHandle;
		this->_graphicsInterface = rhs._graphicsInterface;
	}
}
