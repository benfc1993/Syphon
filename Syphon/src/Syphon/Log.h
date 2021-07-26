#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace Syphon
{
	class SYPHON_API Log
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

//Core log macros

#define SY_CORE_TRACE(...)  ::Syphon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SY_CORE_INFO(...)   ::Syphon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SY_CORE_WARN(...)   ::Syphon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SY_CORE_ERROR(...)  ::Syphon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SY_CORE_FATAL(...)  ::Syphon::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros

#define SY_TRACE(...)  ::Syphon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SY_INFO(...)   ::Syphon::Log::GetClientLogger()->info(__VA_ARGS__)
#define SY_WARN(...)   ::Syphon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SY_ERROR(...)  ::Syphon::Log::GetClientLogger()->error(__VA_ARGS__)
#define SY_FATAL(...)  ::Syphon::Log::GetClientLogger()->critical(__VA_ARGS__)


