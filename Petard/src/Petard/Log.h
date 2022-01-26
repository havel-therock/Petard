#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Petard {

	class PETARD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	
	};

}

#define PD_CORE_TRACE(...)     ::Petard::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PD_CORE_INFO(...)      ::Petard::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PD_CORE_WARN(...)      ::Petard::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PD_CORE_ERROR(...)     ::Petard::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define PD_CORE_FATAL(...)     ::Petard::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define PD_TRACE(...)          ::Petard::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PD_INFO(...)           ::Petard::Log::GetClientLogger()->info(__VA_ARGS__)
#define PD_WARN(...)           ::Petard::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PD_ERROR(...)          ::Petard::Log::GetClientLogger()->error(__VA_ARGS__)
//#define PD_FATAL(...)          ::Petard::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if defined distro build example: PD_DIST_BUILD
// #define PD_INFO <- clears out all PD_INFO macros
