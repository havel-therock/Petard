#include "pdpch.h"
#include "Layer.h"

#include "Petard/Camera/Camera.h"
#include "Petard/Camera/OrtographicCamera.h"
#include "Petard/Camera/PerspectiveCamera.h"
#include "Petard/Application.h"

namespace Petard {

	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
		m_RootScene = std::make_unique<SceneNode>(false);
		m_RenderQueue = std::make_unique<RenderQueue>();
		m_Camera = std::make_unique<Camera>();
		SetCamera(CameraType::NONE); // for now NONE will be interpreted as ORTHOGONAL  // fucking disaster
	}

	void Layer::OnRender()
	{
		// m_RenderQueue->Clear();
		m_RenderQueue->ClearRenderQueue();
		m_RenderQueue->UploadRenderQueue(m_RootScene->GetRenderQueue());
		m_Camera->GetEngineCamera().RecalculateViewMatrix();
		m_RenderQueue->Render(/* MT/ST enum */);
		// ConstructRenderQueueFromSceneGraph();
		// room for optimization.
		// Default behaviour: Each frame clear RenderQUEUE and construct from Scene graph
		// optimize = could odify only changed  Scenenodes inside Renderqueue 
		// UploadRenderQueue(take vector by value (copy))
		// GetRenderQueue() return const reference to created std::vector<RenderableObject>
		// m_RootScene->OnRender(*m_RenderQueue); // it will construct render queue from scene graph;
	}

	void Layer::AddToScene(SceneNode sceneNode)
	{	
		m_RootScene->AddChildNode(sceneNode);
	}

	void Layer::SetCamera(CameraType cameraType)
	{
		m_Camera->SetEngineCamera(cameraType);
		m_RenderQueue->UploadCamera(&(m_Camera->GetEngineCamera()));
	}
	/*
	void Layer::SetCamera(CameraProps)
	{
		m_Camera.reset(new Camera(CameraProps));
		m_RenderQueue->UploadCamera(m_Camera.get());
	}*/
	 
}
