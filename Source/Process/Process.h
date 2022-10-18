#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <Singleton/Singleton.h>

namespace Etanol
{
	class Process : public Singleton<Process>
	{
	public:
		Process(void) = default;
		~Process(void) = default;

		void HideProcess(void);
	};
}

#endif