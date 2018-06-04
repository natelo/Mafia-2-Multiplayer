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

#ifndef _SV_LOCAL_H
#define _SV_LOCAL_H

class svMain {

private:
	bool		sv_isActive;

public:
				svMain(void);
				~svMain(void);

	bool		Initialise(int argc, char * argv[]);
	void		Deinitialise(void);
	void		setActive(bool setActive) { sv_isActive = setActive; };
	bool		isActive(void) { return sv_isActive; }

};

#endif // ~_SV_LOCAL_H