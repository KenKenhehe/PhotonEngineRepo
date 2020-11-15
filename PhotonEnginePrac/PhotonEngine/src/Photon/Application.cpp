#include "PhPch.h"

#include "Application.h"
#include <stdio.h>
#include "Log.h"

#include "Events\ApplicationEvent.h"
#include "Events\KeyEvent.h"
namespace Photon {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
