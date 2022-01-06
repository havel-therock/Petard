#pragma once

#ifdef PD_PLATFORM_WINDOWS
	#ifdef PD_BUILD_DLL
		#define PETARD_API __declspec(dllexport)
	#else
		#define PETARD_API __declspec(dllimport)
	#endif // PD_BUILD_DLL
#else
	#error Platform not supported by Petard! 
#endif // PD_PLATFORM_WINDOWS 
