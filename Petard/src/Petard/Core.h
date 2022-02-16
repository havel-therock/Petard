#pragma once

#ifdef PD_ENABLE_ASSERTS
	#define PD_CORE_ASSERT(x, ...) { if(!(x)) { PD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PD_ASSERT(x, ...) { if(!(x)) { PD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PD_CORE_ASSERT(x, ...) 
	#define PD_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)