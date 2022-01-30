#include <Petard.h>

#include <iostream>


class ExampleLayer : public Petard::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		//PD_INFO("ExampleLayer::Update");

		if (Petard::Input::IsKeyPressed(PD_KEY_TAB))
		{
			PD_INFO("Tab was pressed!");
		}
	}

	void OnEvent(Petard::Event& event) override
	{
		// PD_TRACE("{0}", event);
	}
};

class SandboxApp : public Petard::Application
{
public:
	SandboxApp() 
	{
		PushLayer(new ExampleLayer());
	}

	~SandboxApp()
	{
	}

};

Petard::Application* Petard::CreateApplication()
{
	return new SandboxApp();
}