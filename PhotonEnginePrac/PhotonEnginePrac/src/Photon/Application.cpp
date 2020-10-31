#include "Application.h"
#include <stdio.h>
namespace Photon {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			printf("Running...\n");
		}
	}
}
