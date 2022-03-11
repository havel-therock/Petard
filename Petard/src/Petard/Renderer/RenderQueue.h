#pragma once


namespace Petard{

	class RenderQueue
	{
	public:
		std::vector<std::shared_ptr<SceneNode>> m_RenderQueue;
	};
}