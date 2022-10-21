#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <windows.h>

#if defined( _WIN64 )  
typedef DWORD64 ADDY;
#elif defined( _WIN32 )
typedef DWORD ADDY;
#endif

namespace Etanol
{
	template <class T>
	static void SafeDelete(T*& In)
	{
		if (!In) return;
		delete In;
		In = nullptr;
	}

	template <class T>
	static void SafeDeleteArray(T*& In)
	{
		if (!In) return;
		delete[] In;
		In = nullptr;
	}
}

#endif