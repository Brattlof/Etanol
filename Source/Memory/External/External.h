#ifndef __EXTERNAL_H__
#define __EXTERNAL_H__

#include <Singleton/Singleton.h>
#include <Memory/Memory.h>

#include <TlHelp32.h>
#include <psapi.h>

namespace Etanol
{
	class External : public Singleton<External>
	{
	public:
		External(void) : m_ProcessHandle(NULL), m_Process({}), m_ProcessBase(NULL) {  };
		~External(void) { if (m_ProcessHandle) CloseHandle(m_ProcessHandle); }

		template <class T>
		T Read(const ADDY& address)
		{
			T Out = { };
			ReadProcessMemory(m_ProcessHandle, reinterpret_cast<LPCVOID>(address), &Out, sizeof(T), nullptr);
			return Out;
		}

		template<class T>
		void Write(const ADDY& address, const T& buffer)
		{
			WriteProcessMemory(m_ProcessHandle, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(T), nullptr);
		}

		BOOLEAN SetProcess(const char* process_exe_name);

		PROCESSENTRY32 FindProcess(const char* process_exe_name);
		MODULEENTRY32 FindModule(const char* module_name);

	private:
		HANDLE m_ProcessHandle;
		PROCESSENTRY32 m_Process;
		ADDY m_ProcessBase; // WIP
	};
}

#endif