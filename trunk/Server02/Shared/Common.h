/**
 *
 * About		: Mafia 2 MultiPlayer
 * Project	: Server
 * Developer	: Nate 'L0, <nate.afk@gmail.com>
 *
 * $Rev$
 * $Date$
 * $Author$
 * @file
 */
#pragma warning(disable: 4996)

// OS Depended includes
#ifdef _WIN32
	//#include "WindowsIncludes.h"
	//#include	<windowsx.h>
	#include <windows.h>
#else
	#include "Linux.h"
#endif

// Core includes
#include	<assert.h>

// Shared
#include "CString.h"

// Server Stuff
#define MOD_NAME		"M2:MP"
#define MOD_FULL_NAME	"Mafia 2 : MultiPlayer"
#define MOD_VERSION		"0.1 Alpha"
#ifdef WIN32
	#define MOD_OS		"Windows"
#else
	#define MOD_OS		"Linux"
#endif

#ifdef DEBUG
	#define SERVER_TITLE	MOD_FULL_NAME ", v" MOD_VERSION " /" MOD_OS " /Debug"
#else
	#define SERVER_TITLE	MOD_FULL_NAME ", v" MOD_VERSION " /" MOD_OS
#endif

#ifdef WIN32
#define TERMINATE_PROCESS	TerminateProcess(GetCurrentProcess(), 0);
#else
#define TERMINATE_PROCESS	_exit(42);
#endif

// Macros
#define ARRAY_LENGTH(array)	(sizeof(array) / sizeof(array[0]))
#define	SAFE_DELETE(memory)	{ delete memory; memory = nullptr; }
#define	SAFE_RELEASE(p)	{ if ( (p) ) { (p)->Release(); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(memory) if(memory) { delete [] memory; memory = nullptr; }
#define SAFE_FREE(memory) if(memory) { free(memory); memory = nullptr; }
