#include "pdpch.h"
#include "SceneNode.h"

namespace Petard {
	
	SceneNode::SceneNode(bool renderable, const std::string IdName)
		: m_IdName(IdName), m_Visible(true), m_IsRenderable(renderable)
	{
		// m_visible = true;
		//m_IsRenderable = true;
		// m_IsChanged = false;
		
		//m_RenderableObject = std::unique_ptr<RenderableObject>(new RenderableObject());
		m_RenderableObject = new RenderableObject();
		
		// m_ChildScenes.clear();
		// m_RenderableObject.reset(new RenderableObject());
	}
	
	std::vector<RenderableObject> SceneNode::GetRenderQueue()
	{
		std::vector<RenderableObject> renderableQueue;
		
		ConstructRenderQueue(renderableQueue);

		return renderableQueue;
	}
	
	
	void SceneNode::AddChildNode(SceneNode childNode)
	{
		m_ChildScenes.push_back(std::make_shared<SceneNode>(childNode));
	}

	void SceneNode::ConstructRenderQueue(std::vector<RenderableObject>& renderQueue)
	{	
		for (auto& childScene : m_ChildScenes)
		{
			childScene->ConstructRenderQueue(renderQueue);
		}
		if (m_IsRenderable == true) {
			renderQueue.push_back(*m_RenderableObject);
		}
		
	}
	/*
	void SceneNode::OnRender(RenderQueue& renderQueue)
	{
		// check if this is skipped when m_ChildScenes = NULL (empty)

		for (auto& childScene : m_ChildScenes)
		{
			childScene->OnRender(renderQueue);
		}

		if (m_IsRenderable == true) {
			// std::cout << "elo elo";
			renderQueue.PushRenderableObejctToQueue(*m_RenderableObject);
		}

	}
	*/
}