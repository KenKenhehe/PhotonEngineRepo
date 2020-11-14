#include "PhPch.h"

#include "Application.h"
#include <stdio.h>
#include "Log.h"

#include "Events\ApplicationEvent.h"
#include "Events\KeyEvent.h"
namespace Photon {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1270, 860);
		PH_CORE_TRACE(e);

		KeyPressEvent e2(2, 10);
		PH_CORE_TRACE(e2);

		KeyReleasedEvent e3(10);
		PH_CORE_TRACE(e3);
		while (true)
		{
			
		}
	}
}
