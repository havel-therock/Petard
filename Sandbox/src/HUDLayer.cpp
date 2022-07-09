#include "HUDLayer.h"

HUDLayer::HUDLayer()
	: Layer("HUDLayer")
{
	
}

void HUDLayer::OnAttach()
{
	Petard::Primitive p_Circle(Petard::PrimitiveType::CIRCLE);
	p_Circle.m_RenderableObject->m_Position = glm::vec3(3.0f, 0.0f, -10.0f);
	AddToScene(p_Circle);
}

void HUDLayer::OnDetach()
{

}

void HUDLayer::OnUpdate()
{
	ZBufferToggle(false);
	static int direction = 1;
	if (Petard::Input::IsKeyPressed(PD_KEY_H))
	{

		glm::vec3 pos = GetCamera().GetPosition();
		if (pos.y > 1.0f || pos.y < -1.0f)
			direction *= -1;
		GetCamera().SetPosition(pos + glm::vec3({ 0.0, direction * 0.1, 0.0 }));
	}
}

void HUDLayer::OnEvent(Petard::Event& event)
{
	Petard::EventDispatcher worker(event);
	worker.Dispatch<Petard::MouseScrolledEvent>(PD_BIND_EVENT_FN(HUDLayer::OnMouseScrollEvent));
}

bool HUDLayer::OnMouseScrollEvent(Petard::MouseScrolledEvent event)
{
	PD_INFO("{0} passed to HUD layer but not handled", event.ToString());
	return false; // if event is handeled return true else return false
}