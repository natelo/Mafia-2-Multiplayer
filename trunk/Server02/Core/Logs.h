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
#pragma once

#include <stdio.h>
#include "Threading\CMutex.h"

class Logs
{
private:
	static FILE	*l_filePtr;
	static bool l_logTime;
	static CMutex l_mutex;

public:

	static	void	Open(const char * szLogFile, bool bAppend = false);
	static	void	Print(const char * szString);
	static	void	Printf(const char * szFormat, ...);
	static	void	PrintToFile(const char * szString);
	static	void	PrintfToFile(const char * szFormat, ...);
	static	void	Close(void);
	static	void	TimeStamp(bool bEnable);
};

/**
 * @def Helper macro to support debug only log message.
 */
#ifndef DEBUG_LOG
#	ifdef _DEBUG
#		define DEBUG_LOG(message,...) CLogFile::Printf(message, __VA_ARGS__)
#	else
#		define DEBUG_LOG(...)
#	endif
#endif