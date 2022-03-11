#pragma once
#include "SceneNode.h"


namespace Petard {

	class SceneManager
	{
	public:
		SceneManager(std::shared_ptr<SceneNode> RootScene);
		
		std::shared_ptr<SceneNode> GetNodeByName(const std::string& IdName) const;
		void RenderScene();

	private:
		std::shared_ptr<SceneNode> m_RootScene;
		// void OptimizeAndPrepareForRendering(); 
		// optimize whole scene... with all childs 
		// called as a first line in RenderScene();
		// opptimize function could be 
		// determine order of rendering SceneNodes
		// what to render and what not
		// outputs vector of grouped similar objects of same shader etc.. ready for instancedDrawCall
		// sorting()
		
		// std::vector<SceneNode> m_RenderQueue; /cleared after render, catch submit calls to Renderer3D
	};
}