#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Petard/Events/ApplicationEvent.h"
#include "Petard/LayerStack.h"

namespace Petard {

	class PETARD_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}

