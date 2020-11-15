#pragma once

#include "PhPch.h"
#include "Core.h"

#include "Window.h"
namespace Photon {
	class PHOTON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//Be defined by CLIENT
	Application* CreateApp();
}

