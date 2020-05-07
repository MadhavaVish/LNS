#pragma once

#include "core.h"

#include <memory>
#include "spdlog/spdlog.h"

namespace LNS {

	class LNS_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//Core log macros
#define LNS_CORE_TRACE(...) ::LNS::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LNS_CORE_INFO(...)  ::LNS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LNS_CORE_WARN(...)  ::LNS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LNS_CORE_ERROR(...) ::LNS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LNS_CORE_FATAL(...) ::LNS::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define LNS_TRACE(...)      ::LNS::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LNS_INFO(...)       ::LNS::Log::GetClientLogger()->info(__VA_ARGS__)
#define LNS_WARN(...)       ::LNS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LNS_ERROR(...)      ::LNS::Log::GetClientLogger()->error(__VA_ARGS__)
#define LNS_FATAL(...)      ::LNS::Log::GetClientLogger()->fatal(__VA_ARGS__)

