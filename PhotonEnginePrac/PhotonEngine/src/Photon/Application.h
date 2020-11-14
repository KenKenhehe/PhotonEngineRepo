#pragma once

#include "Core.h"
#include "PhPch.h"
namespace Photon {
	class PHOTON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	//Be defined by CLIENT
	Application* CreateApp();
}

