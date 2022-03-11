#include "pdpch.h"
#include "SceneNode.h"

namespace Petard {
	
	SceneNode::SceneNode(const std::string IdName)
		: m_IdName(IdName) {}
	
	SceneNode::~SceneNode()
	{
	}

	void SceneNode::Init()
	{
	}

	void SceneNode::AddChildNode(SceneNode& child)
	{
	}

	std::shared_ptr<SceneNode> SceneNode::GetParent()
	{
		return std::shared_ptr<SceneNode>();
	}

}