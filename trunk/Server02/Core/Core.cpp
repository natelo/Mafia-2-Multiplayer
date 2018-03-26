#include "Core.h"

Core::Core(void)
{
}

Core::~Core(void)
{
}

bool Core::Initialise(int argc, char * argv[])
{

#ifdef WIN32
	// Set the console window
	SetConsoleTitle(SERVER_TITLE);
#endif

	return true;
}

void Core::Deinitialise(void)
{
}


