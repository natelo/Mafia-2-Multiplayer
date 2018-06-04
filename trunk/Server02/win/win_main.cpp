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
#include <Windows.h>
#include "win\win_local.h"
#include "shared\shared.h"
#include "server/server.h"

svMain *pServer = NULL;

/**
 * @fn	int main(int args, char *argv[])
 *
 * @brief	Main entry-point for this application
 *
 * @author	Nate
 * @date	26. 03. 2018
 *
 * @param	args	The number of command-line arguments provided.
 * @param	argv	An array of command-line argument strings.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */
int main(int args, char *argv[]) {	

	pServer = new svMain;

	if (!pServer || !pServer->Initialise(args, argv))
	{
		// Process terminating 
		TerminateProcess(GetCurrentProcess(), 0);
	}
	
	while (pServer->isActive()) 
	{		
		
	}

	SAFE_DELETE(pServer);

	return 0;
}
