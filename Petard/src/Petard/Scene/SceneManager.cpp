#include "pdpch.h"
#include "SceneManager.h"

#include "SceneNode.h"

namespace Petard {

	SceneManager::SceneManager(/*std::shared_ptr<SceneNode> RootScene*/)
		/* : m_RootScene(RootScene) */ {}

	std::shared_ptr<SceneNode> SceneManager::GetNodeByName(const std::string& IdName) const
	{
		//for i
		return std::shared_ptr<SceneNode>();
	}
	void SceneManager::RenderScene()
	{

	}
}