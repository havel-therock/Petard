#pragma once
#include "CameraProperties.h"
#include "EngineCamera.h"

namespace Petard {

	class  PerspectiveCamera : public EngineCamera
	{
	public:
		PerspectiveCamera(CameraProperties* cameraProperties);
	
		inline const glm::mat4& GetProjectionMatrix() const { return m_CameraProps->m_ProjectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return m_CameraProps->m_ViewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return m_CameraProps->m_ViewProjectionMatrix; }
		
	// could be private?
		void RecalculateViewMatrix();
		// void RecalculateProjectionMatrix();

	private:
		CameraProperties* m_CameraProps;
	};
}