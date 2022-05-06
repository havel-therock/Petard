#pragma once

#include "pdpch.h"

#include "Petard/Core.h"
#include "Petard/Events/Event.h"

namespace Petard {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		
		WindowProps(const std::string& title = "Petard Engine",
			unsigned int width = 1200,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		// update GLFW, swap buffers, poll input events. Shuould be called one time per frame
		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0; // GLFW <or any other API> window pointer

		static Window* Create(const WindowProps& props = WindowProps());
	};
}