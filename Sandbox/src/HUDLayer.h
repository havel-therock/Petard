#pragma once
#include <Petard.h>

class HUDLayer : public Petard::Layer
{
public:
	HUDLayer();
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void OnEvent(Petard::Event& event) override;
};
