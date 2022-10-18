#include "Process.h"

using namespace Etanol;

#include <Sys/ntdll.h>

void Process::HideProcess(void)
{
#if _WIN32 || _WIN64

	#if _WIN64
		return;
	#else
		return;
	#endif

#else
	return;
#endif
}