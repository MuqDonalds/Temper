#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Temper {

	class TEMPER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger>  s_CoreLogger;
		static std::shared_ptr<spdlog::logger>  s_ClientLogger;

	};
}

// Core log macros
#define TP_CORE_CRITICAL(...)    Temper::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define TP_CORE_ERROR(...)       Temper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TP_CORE_WARN(...)        Temper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TP_CORE_INFO(...)        Temper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TP_CORE_TRACE(...)       Temper::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define TP_CRITICAL(...)         Temper::Log::GetClientLogger()->critical(__VA_ARGS__)
#define TP_ERROR(...)            Temper::Log::GetClientLogger()->error(__VA_ARGS__)
#define TP_WARN(...)             Temper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TP_INFO(...)             Temper::Log::GetClientLogger()->info(__VA_ARGS__)
#define TP_TRACE(...)            Temper::Log::GetClientLogger()->trace(__VA_ARGS__)