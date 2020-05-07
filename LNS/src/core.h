#pragma once

#ifdef LNS_PLATFORM_WINDOWS
    #ifdef LNS_BUILD_DLL
        #define LNS_API __declspec(dllexport)
    #else
        #define LNS_API __declspec(dllimport)
    #endif
#else
	#define LNS_API 
#endif