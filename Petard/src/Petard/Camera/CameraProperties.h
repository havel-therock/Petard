#pragma once
#include "pdpch.h"
#include "glm/glm.hpp"

namespace Petard {

	enum class CameraType
	{
		NONE = 0,
		ORTHOGONAL,
		PERSPECTIVE,
		IZOMETRIC
		//...
	};
	
	// Pure data class (refactor initializer/constructor)
	class CameraProperties
	{
	public:
		CameraProperties() 
			: m_CameraType(CameraType::NONE),
			m_Position(glm::vec3(0.0f)),
			m_Rotation(glm::vec3(0.0f)),
			m_RenderDistance(100.0f),
			m_ProjectionMatrix(glm::mat4(1.0f)),
			m_ViewMatrix(glm::mat4(1.0f)),
			m_ViewProjectionMatrix(glm::mat4(1.0f)),
			m_Zoom(1.0f),
			m_FOV(45.0f)
			{ }
		
		// ORTHOGONAL, PERSPECTIVE
		CameraType m_CameraType;
		glm::vec3 m_Position; // quaternions chage to vec4 ? 
		glm::vec3 m_Rotation;
		float m_RenderDistance;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		// float m_Aspect;

		// ORTHOGONAL
		float m_Zoom;
		
	
		// PERSPECTIVE
		// FOV as angle in degrees for perspective is just FOV for orthographic it is width of frustum
		float m_FOV;
	};
}