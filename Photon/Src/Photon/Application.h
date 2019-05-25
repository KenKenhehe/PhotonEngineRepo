#pragma once
#include "core.h"
namespace Photon {


	class PHOTON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	//To be defined in a client
	Application* CreateApplication();
}
