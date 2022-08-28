#pragma once

#include <memory>
#include <string_view>
#include "spdlog/spdlog.h"

class spdlog::logger;

namespace tk
{
	class Log
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetAppLogger();

	private:

		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> appLogger;
		
	};
}

#define TK_CORE_FATAL(...)	tk::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define TK_CORE_ERROR(...)	tk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TK_CORE_WARN(...)	tk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TK_CORE_INFO(...)	tk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TK_CORE_TRACE(...)	tk::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define TK_FATAL(...)	tk::Log::GetAppLogger()->fatal(__VA_ARGS__)
#define TK_ERROR(...)	tk::Log::GetAppLogger()->error(__VA_ARGS__)
#define TK_WARN(...)	tk::Log::GetAppLogger()->warn(__VA_ARGS__)
#define TK_INFO(...)	tk::Log::GetAppLogger()->info(__VA_ARGS__)
#define TK_TRACE(...)	tk::Log::GetAppLogger()->trace(__VA_ARGS__)