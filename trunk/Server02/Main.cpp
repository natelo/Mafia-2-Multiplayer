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
#include "CCommon.h"
#include "Core\Core.h"

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

	Core *pCore = new Core;

	if (!pCore || !pCore->Initialise(args, argv))
	{
		// Process terminating 
#ifdef WIN32
		TerminateProcess(GetCurrentProcess(), 0);
#else
		_exit(42);
#endif
	}

	while (pCore->IsActive()) 
	{		
		
	}

	SAFE_DELETE(pCore);

	return 0;
}