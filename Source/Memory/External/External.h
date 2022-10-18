#ifndef __EXTERNAL_H__
#define __EXTERNAL_H__

#include <Singleton/Singleton.h>

#include <windows.h>
#include <TlHelp32.h>
#include <psapi.h>

namespace Etanol
{
	class External : public Singleton<External>
	{
	public:
		External(void) : ProcessBase(NULL), m_ProcessHandle(NULL), m_Process({ }) {  };
		~External(void) { if (m_ProcessHandle) CloseHandle(m_ProcessHandle); }

		template <class T>
		T Read(const DWORD& address)
		{
			T Out = { };
			ReadProcessMemory(m_ProcessHandle, (LPCVOID)address, &Out, sizeof(T), nullptr);
			return Out;
		}

		BOOLEAN SetProcess(const char* process_exe_name);

		PROCESSENTRY32 FindProcess(const char* process_exe_name);
		MODULEENTRY32 FindModule(const char* module_name);


	public:
		DWORD ProcessBase;

	private:
		HANDLE m_ProcessHandle;
		PROCESSENTRY32 m_Process;
	};
}

#endif