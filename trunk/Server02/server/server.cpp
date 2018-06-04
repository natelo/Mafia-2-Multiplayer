/**
 * 
 * About		: Mafia 2 MultiPlayer
 * Project		: Server
 * Developer	: Nate 'L0, <nate.afk@gmail.com>
 *
 * $Rev$
 * $Date$
 * $Author$
 * @file
 */
#include "server\server.h"

svMain::svMain(void){

}

svMain::~svMain(void) {

}

bool svMain::Initialise(int argc, char * argv[])
{
	setActive(true);

	return isActive();
}

void svMain::Deinitialise(void)
{
}
