#ifndef __INC_LZO_MANAGER_H
#define __INC_LZO_MANAGER_H

#include "minilzo.h"

class LZOManager : public singleton<LZOManager>
{
	public:
		LZOManager();
		virtual ~LZOManager();

		bool	Compress(const BYTE* src, size_t srcsize, BYTE* dest, lzo_uint * puiDestSize);
		bool	Decompress(const BYTE* src, size_t srcsize, BYTE* dest, lzo_uint * puiDestSize);
		size_t	GetMaxCompressedSize(size_t original);

		BYTE *	GetWorkMemory() { return m_workmem; }

	private:
		BYTE *	m_workmem;
};

#endif
//martysama0134's ec11de26810c4b4081710343a364aa44
