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

class Core
{
private:
	bool		c_gActive;

public:

				Core(void);
				~Core(void);

	bool		Initialise(int argc, char * argv[]);
	void		Deinitialise(void);
	void		SetActive(bool cActive)						{ c_gActive = cActive; }
	bool		IsActive(void)								{ return c_gActive; }
};
