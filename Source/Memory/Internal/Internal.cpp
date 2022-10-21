#include "Internal.h"
#include <winternl.h>

using namespace Etanol;

Internal::Internal(void) : m_Base(NULL)
{
#if defined( _WIN64 )  
    m_Base = Read<ADDY>(__readgsqword(0x60 /* PEBOffset */) + 0x10 /* ListOffset */);
#elif defined( _WIN32 )  
    m_Base = Read<Addy>(__readfsdword(0x30 /* PEBOffset */) + 0x0C /* ListOffset */);
#endif 
}