#ifndef __INTERNAL_H__
#define __INTERNAL_H__

#include <Singleton/Singleton.h>
#include <Memory/Memory.h>

namespace Etanol
{
	class Internal : public Singleton<Internal>
	{
	public:
		Internal(void);
		~Internal(void) = default;

		template <class T>
		T Read(const ADDY& address)
		{
			return *(T*)address;
		}

		template <class T>
		void Write(const ADDY& address, const T& buffer)
		{
			*(T*)address = buffer;
		}

		const ADDY GetBase(void) { return m_Base; }

	private:
		ADDY m_Base;
	};
}

#endif