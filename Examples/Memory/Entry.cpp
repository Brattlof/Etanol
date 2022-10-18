#include <iostream>

#include "Memory/Memory.h"

#include <Memory/External/External.h>

int main(void)
{
	Etanol::External::Init();

	while (true)
	{
		Etanol::External& rExternal = Etanol::External::GetInstance();

		std::cout << rExternal.m_Pid << "\n";
	}

	Etanol::External::Deinit();
}