#pragma once

#ifdef TP_PLATFORM_WINDOWS
	#ifdef TEMPER_BUILD_DLL
		#define TEMPER_API _declspec(dllexport)
    #else
		#define TEMPER_API _declspec(dllimport)
    #endif
#else
	#error Temper Client only supports Windows.
#endif