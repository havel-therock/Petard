#pragma once

namespace Petard {

	class SceneNode
	{
	public:
		SceneNode(const std::string IdName = "SceneNode");
		virtual ~SceneNode();

		// virtual void Init(); 
		void AddChildNode(SceneNode& child);
		virtual void Draw() = 0; // draw call of this specific scene, each scene has instruction how to draw itself. virtual pure // use submit calls of render3d::submit(vertex array, shader)
		virtual void OnUpdate() = 0;
		void OnRender(); // trigger all drawCalls of child nodes then draw itself 
		// virtual std::shared_ptr<SceneNode> GetParent();
		
		//static std::shared_ptr<SceneNode> GetNodeByName(std::string IdName) {return reference}

	
		inline const std::string& GetName() const { return m_IdName; }
		// inline const std::shared_ptr<SceneNode> Get
	protected:
		std::string m_IdName;
		std::vector<SceneNode> m_ChildScenes;
	private:

		// std::pair<const std::string, std::shared_ptr<SceneNode>> m_ChildNodes; // pair <IDName, SceneNode>
		//std::shared_ptr<SceneNode> m_ParentNode;
		//VertexBuffer
		//IndexBuffer
		//shader
		//uniforms
	};
}

