#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Petard/Events/ApplicationEvent.h"
#include "Petard/LayerStack.h"
#include "Petard/Renderer/Shader/Shader.h"
#include "Petard/Renderer/Buffer.h"
#include "Petard/Renderer/VertexArray.h"

namespace Petard {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }


	private:
		// void RenderLayer(Layer layer) { layer.OnRender(); }
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}

