#pragma once
#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"
#include "spdlog\fmt\ostr.h"
namespace Photon {
	class PHOTON_API Log
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

//Log for core engine info
#define PH_CORE_FATAL(...) ::Photon::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define PH_CORE_ERROR(...) ::Photon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PH_CORE_WARN(...) ::Photon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PH_CORE_INFO(...) ::Photon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PH_CORE_TRACE(...) ::Photon::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Log for app info
#define PH_FATAL(...) ::Photon::Log::GetClientLogger()->critical(__VA_ARGS__)
#define PH_ERROR(...) ::Photon::Log::GetClientLogger()->error(__VA_ARGS__)
#define PH_WARN(...) ::Photon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PH_INFO(...) ::Photon::Log::GetClientLogger()->info(__VA_ARGS__)
#define PH_TRACE(...) ::Photon::Log::GetClientLogger()->trace(__VA_ARGS__)