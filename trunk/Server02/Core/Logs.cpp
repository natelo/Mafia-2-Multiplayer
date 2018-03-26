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
#include "Logs.h"
#include "SharedUtility.h"

#ifdef _WIN32
#include	<windows.h>
#include	<direct.h>
#else
#include	<stdarg.h>
#endif

#include	<errno.h>

FILE 		*Logs::l_filePtr = NULL;
bool 		Logs::l_logTime = true;
CMutex		Logs::l_mutex;

void Logs::Open(const char * szLogFile, bool bAppend)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Open the log file
	l_filePtr = fopen(szLogFile, bAppend ? "a" : "w");

	// Unlock the mutex
	l_mutex.Unlock();
}

void Logs::Print(const char * szString)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Print the message
	if (l_logTime)
		printf("[%s] %s\n", SharedUtility::GetTimeString(), szString);
	else
		printf("%s\n", szString);

	// Flush the output buffer
	fflush(stdout);

	// Unlock the mutex
	l_mutex.Unlock();

	// Print the message to the log file
	PrintToFile(szString);

#ifdef _WIN32
	// Print message to VS output.
	OutputDebugStringA(szString);
	OutputDebugStringA("\r\n");
#endif
}

void Logs::Printf(const char * szFormat, ...)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Collect the arguments
	va_list vaArgs;
	char szBuffer[1024];
	va_start(vaArgs, szFormat);
	vsnprintf(szBuffer, sizeof(szBuffer), szFormat, vaArgs);
	va_end(vaArgs);

	// Unlock the mutex
	l_mutex.Unlock();

	// Print the message
	Print(szBuffer);
}

void Logs::PrintToFile(const char * szString)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Is the log file open?
	if (l_filePtr)
	{
		// Log the message
		if (l_logTime)
			fprintf(l_filePtr, "[%s] %s\n", SharedUtility::GetTimeString(), szString);
		else
			fprintf(l_filePtr, "%s\n", szString);

		// Flush the log file buffer
		fflush(l_filePtr);
	}

	// Unlock the mutex
	l_mutex.Unlock();
}

void Logs::PrintfToFile(const char * szFormat, ...)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Collect the arguments
	va_list vaArgs;
	char szBuffer[1024];
	va_start(vaArgs, szFormat);
	vsnprintf(szBuffer, sizeof(szBuffer), szFormat, vaArgs);
	va_end(vaArgs);

	// Unlock the mutex
	l_mutex.Unlock();

	// Print the message to the log file
	PrintToFile(szBuffer);
}

void Logs::Close(void)
{
	// Lock the mutex
	l_mutex.TryLock(1);

	// Is the log file open?
	if (l_filePtr)
	{
		// Close the log file
		fclose(l_filePtr);
		l_filePtr = NULL;
	}

	// Unlock the mutex
	l_mutex.Unlock();
}

void Logs::TimeStamp(bool bEnable)
{
	l_logTime = bEnable;
}
