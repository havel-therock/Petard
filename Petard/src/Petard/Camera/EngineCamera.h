#pragma once
#include "glm/glm.hpp"

namespace Petard {

	// Interface for Engine cameras:
	class EngineCamera
	{
	public:
		virtual ~EngineCamera() {};
		// functions used by engine 
		virtual const glm::mat4& GetViewProjectionMatrix() const = 0;
		virtual void RecalculateViewMatrix() = 0;
		// virtual void RecalculateData() = 0;
	};
}