#pragma once
#pragma once

#ifdef LNS_PLATFORM_WINDOWS
    #define LNS_API __declspec(dllexport)
#else
	#define LNS_API 
#endif

#include <string>

namespace LNS
{
    LNS_API std::string TestFunction();
}
