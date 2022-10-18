#ifndef __EXTERNAL_H__
#define __EXTERNAL_H__

#include <Singleton/Singleton.h>

#include <windows.h>

namespace Etanol
{
	class External : public Singleton<External>
	{
	public:
		External(void) : m_Handle(NULL), m_Pid(NULL) {  };
		~External(void) { if (m_Handle) CloseHandle(m_Handle); }

	public:
		HANDLE m_Handle;
		DWORD m_Pid;
	};
}

#endif