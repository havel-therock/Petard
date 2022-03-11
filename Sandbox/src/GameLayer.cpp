#include "pdpch.h"
#include "GameLayer.h"
#include "Petard.h"

#include "Level.h"

GameLayer::GameLayer() 
	: Layer("GameLayer") {}


void GameLayer::OnAttach()
{
	m_RootScene = std::make_shared<Petard::SceneNode>(new Level("Level_1"));
	m_RootScene.LoadScene();
}

void GameLayer::OnDetach()
{
}


void GameLayer::OnUpdate(/*Petard::Timestep ts*/) // deltatime time between frames so the movemnt would be independant from frame rate
{
	// Logic
	
	// m_RootScene.OnUpdate(ts);
	// m_Level.GetPlayer().GetPos() m_Level equals root of the scene?

	// Render
	// Petard::RenderCommand::SetClearColor({})
	// Petard::RenderCommand::Clear();

	// Petard::Renderer3D::BeginScene(camera, light, environment);
	// m_RootScene.OnRender(); m_SceneManager.RenderScene(); // RenderScene() change name to OnRender()?
	// Petard::Renderer3D::EndScene();
}

void GameLayer::OnEvent(Petard::Event& event)
{

}
