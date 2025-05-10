#ifndef __HEADER_VNUM_HELPER__
#define	__HEADER_VNUM_HELPER__
#include "length.h"

class CItemVnumHelper
{
public:

	static	const bool	IsPhoenix(DWORD vnum)				{ return 53001 == vnum; }

	static	const bool	IsRamadanMoonRing(DWORD vnum)		{ return 71135 == vnum; }

	static	const bool	IsHalloweenCandy(DWORD vnum)		{ return 71136 == vnum; }

	static	const bool	IsHappinessRing(DWORD vnum)		{ return 71143 == vnum; }

	static	const bool	IsLovePendant(DWORD vnum)		{ return 71145 == vnum; }
};

class CMobVnumHelper
{
public:

	static	bool	IsPhoenix(DWORD vnum)				{ return 34001 == vnum; }
	static	bool	IsIcePhoenix(DWORD vnum)				{ return 34003 == vnum; }

	static	bool	IsPetUsingPetSystem(DWORD vnum)	{ return (IsPhoenix(vnum) || IsReindeerYoung(vnum)) || IsIcePhoenix(vnum); }

	static	bool	IsReindeerYoung(DWORD vnum)	{ return 34002 == vnum; }

	static	bool	IsRamadanBlackHorse(DWORD vnum)		{ return 20119 == vnum || 20219 == vnum || 22022 == vnum; }

	static const bool IsNPCType(BYTE type)
	{
		switch (type)
		{
		case CHAR_TYPE_NPC:
		case CHAR_TYPE_HORSE:
		case CHAR_TYPE_PET:
		case CHAR_TYPE_PET_PAY:
			return true;
		default:
			return false;
		}
	}
};

class CVnumHelper
{
};

#endif	//__HEADER_VNUM_HELPER__
//martysama0134's ec11de26810c4b4081710343a364aa44
