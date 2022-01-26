#include "pdpch.h"
#include "Application.h"

#include "Petard/Events/ApplicationEvent.h"
#include "Petard/Log.h"


namespace Petard {
	
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(300, 1000);
		PD_WARN(e);
		while (true);
	}
}
