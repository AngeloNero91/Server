#include "desc.h"

class DESC_P2P : public DESC
{
	public:
		virtual ~DESC_P2P();

		virtual void	Destroy();
		virtual void	SetPhase(int iPhase);
		bool		Setup(LPFDWATCH _fdw, socket_t fd, const char * host, WORD wPort);
};
//martysama0134's ec11de26810c4b4081710343a364aa44
