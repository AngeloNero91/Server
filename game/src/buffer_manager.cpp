#include "stdafx.h"
#include "buffer_manager.h"

TEMP_BUFFER::TEMP_BUFFER(int Size, bool bForceDelete)
{
	forceDelete = bForceDelete;

	if (forceDelete)
		Size = MAX(Size, 1024 * 128);

	buf = buffer_new(Size);
}

TEMP_BUFFER::~TEMP_BUFFER()
{
	buffer_delete(buf);
}

const void * TEMP_BUFFER::read_peek()
{
	return (buffer_read_peek(buf));
}

void TEMP_BUFFER::write(const void * data, int size)
{
	buffer_write(buf, data, size);
}

int TEMP_BUFFER::size()
{
	return buffer_size(buf);
}

void TEMP_BUFFER::reset()
{
	buffer_reset(buf);
}
//martysama0134's ec11de26810c4b4081710343a364aa44
