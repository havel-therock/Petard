#pragma once
#include "Petard/Renderer/RenderQueue.h"
#include "Petard/Renderer/RenderableObject.h"

namespace Petard {
	
	class SceneNode
	{
	public:
		SceneNode(bool renderable, const std::string IdName = "SceneNode");
		~SceneNode() {};

		std::vector<RenderableObject> GetRenderQueue();
		// virtual void Init(); 
		void AddChildNode(SceneNode childNode);
		
		virtual inline const std::string& GetOrginalClassName() const { return "SceneNode"; }
		// virtual void Draw() = 0; // draw call of this specific scene, each scene has instruction how to draw itself. virtual pure // use submit calls of render3d::submit(vertex array, shader)
		/*virtual*/ 
		void OnUpdate() {}
		// void OnRender(RenderQueue& renderQueue); // trigger all drawCalls of child nodes then draw itself 
		// virtual std::shared_ptr<SceneNode> GetParent();
		
		//static std::shared_ptr<SceneNode> GetNodeByName(std::string IdName) {return reference}

	
		inline const std::string& GetName() const { return m_IdName; }
		// inline const std::shared_ptr<SceneNode> Get

	
	//tmp in public
		bool m_Visible;
		// bool m_IsChanged;
		bool m_IsRenderable;

		// std::unique_ptr<RenderableObject> m_RenderableObject;
		RenderableObject* m_RenderableObject;
		std::vector<std::shared_ptr<SceneNode>> m_ChildScenes;
	
	
	protected:
		std::string m_IdName;

	private:
		void ConstructRenderQueue(std::vector<RenderableObject>& renderQueue);

	//	bool m_visible = true;
	//	bool m_IsChanged = false;
	//	std::vector<SceneNode> m_ChildScenes;
	//private:
	//	RenderableObject m_RenderableObject; // = std::make_shared<RenderableObject>();
		
		// std::pair<const std::string, std::shared_ptr<SceneNode>> m_ChildNodes; // pair <IDName, SceneNode>
		//std::shared_ptr<SceneNode> m_ParentNode;
		//VertexBuffer
		//IndexBuffer
		//shader
		//uniforms
	};
}

