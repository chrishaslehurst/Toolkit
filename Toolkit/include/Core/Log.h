#pragma once

#include <memory>
#include "spdlog/spdlog.h"

class spdlog::logger;

namespace toolkit
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

#define TK_CORE_FATAL(...)	toolkit::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define TK_CORE_ERROR(...)	toolkit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TK_CORE_WARN(...)	toolkit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TK_CORE_INFO(...)	toolkit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TK_CORE_TRACE(...)	toolkit::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define TK_FATAL(...)	toolkit::Log::GetAppLogger()->fatal(__VA_ARGS__)
#define TK_ERROR(...)	toolkit::Log::GetAppLogger()->error(__VA_ARGS__)
#define TK_WARN(...)	toolkit::Log::GetAppLogger()->warn(__VA_ARGS__)
#define TK_INFO(...)	toolkit::Log::GetAppLogger()->info(__VA_ARGS__)
#define TK_TRACE(...)	toolkit::Log::GetAppLogger()->trace(__VA_ARGS__)