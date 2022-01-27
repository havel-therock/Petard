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

#ifdef PD_ENABLE_ASSERTS
	#define PD_CORE_ASSERT(x, ...) { if(!(x)) { PD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PD_ASSERT(x, ...) { if(!(x)) { PD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PD_CORE_ASSERT(x, ...) 
	#define PD_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)