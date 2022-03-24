#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace toolkit
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::appLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v %$");
		// #todo-ch 24/03/2022: expose log level at some point?
		coreLogger = spdlog::stdout_color_mt("Toolkit");
		coreLogger->set_level(spdlog::level::trace);

		appLogger = spdlog::stdout_color_mt("App");
		appLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return coreLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetAppLogger()
	{
		return appLogger;
	}

}