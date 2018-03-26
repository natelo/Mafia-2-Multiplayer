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
#include "Shared\Common.h"
#include "Core\Core.h"

int main(int args, char *argv[]) {

	Core *pCore = new Core;

	if (!pCore || !pCore->Initialise(args, argv))
	{
		TERMINATE_PROCESS
	}

	while (pCore->IsActive()) 
	{		
		
	}

	SAFE_DELETE(pCore);

	return 0;
}