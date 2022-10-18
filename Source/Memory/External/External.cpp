#include "External.h"

using namespace Etanol;

#include <iostream>

BOOLEAN External::SetProcess(const char* process_exe_name)
{
	if (m_ProcessHandle) CloseHandle(m_ProcessHandle);
	m_Process = { };
	ProcessBase = NULL;

	m_Process = FindProcess(process_exe_name);
	if (!m_Process.th32ProcessID) return 0x0;

	if (m_ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_Process.th32ProcessID))
	{
		HMODULE lphModule[1024];
		DWORD lpcbNeeded(NULL);

		if (!EnumProcessModules(m_ProcessHandle, lphModule, sizeof(lphModule), &lpcbNeeded))
		{
			return 0x0;
		}

		TCHAR szModName[MAX_PATH];
		if (!GetModuleFileNameEx(m_ProcessHandle, lphModule[0], szModName, sizeof(szModName) / sizeof(TCHAR)))
		{
			return 0x0;
		}

		ProcessBase = (DWORD)lphModule[0];

		return 0x1;
	}

	return 0x0;
}

PROCESSENTRY32 External::FindProcess(const char* process_exe_name)
{
	HANDLE SnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0x0);

	PROCESSENTRY32 ProcessEntry = { };
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);

	for (Process32First(SnapshotHandle, &ProcessEntry); Process32Next(SnapshotHandle, &ProcessEntry);)
	{
		if (!strcmp(ProcessEntry.szExeFile, process_exe_name))
		{
			CloseHandle(SnapshotHandle);
			return ProcessEntry;
		}
	}

	CloseHandle(SnapshotHandle);
	return { };
}

MODULEENTRY32 External::FindModule(const char* module_name)
{
	HANDLE SnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_Process.th32ProcessID);

	MODULEENTRY32 ModEntry = { };
	ModEntry.dwSize = sizeof(MODULEENTRY32);

	for (Module32First(SnapshotHandle, &ModEntry); Module32Next(SnapshotHandle, &ModEntry);)
	{
		std::cout << ModEntry.szModule << "\n";

		if (!strcmp(ModEntry.szModule, module_name))
		{
			CloseHandle(SnapshotHandle);
			return ModEntry;
		}
	}

	CloseHandle(SnapshotHandle);
	return { };
}