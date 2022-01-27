#include "pdpch.h"
#include "Application.h"

#include "Petard/Events/ApplicationEvent.h"
#include "Petard/Log.h"


namespace Petard {
	
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
