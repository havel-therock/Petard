#pragma once
#include <Petard.h>

class GameLayer : public Petard::Layer
{
public:
	GameLayer();
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void OnEvent(Petard::Event& event) override;

	void LoadLevel();
	// Petard::SceneManager m_SceneManager;
	//std::shared_ptr<Petard::SceneNode> m_RootScene;
private:
	bool OnMouseScrollEvent(Petard::MouseScrolledEvent event);
};

/*
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
*/