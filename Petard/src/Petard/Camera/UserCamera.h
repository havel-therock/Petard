#pragma once
#include "CameraProperties.h"

namespace Petard {
	
	class UserCamera
	{
	public:
		UserCamera(CameraProperties* cameraProperties)
			: m_CameraProps(cameraProperties) {}

		inline const glm::vec3& GetPosition() const { return m_CameraProps->m_Position; }
		inline void SetPosition(const glm::vec3& position) { m_CameraProps->m_Position = position; }
		inline const glm::vec3& GetRotation() const { return m_CameraProps->m_Rotation; }
		inline void SetRotation(const glm::vec3& rotation) { m_CameraProps->m_Rotation = rotation; }
		inline const float GetZoom() const { return m_CameraProps->m_Zoom; }
		inline void SetZoom(float zoom) { m_CameraProps->m_Zoom = zoom; }
		inline const float GetRenderDistance() const { return m_CameraProps->m_RenderDistance; }
		inline void SetRenderDistance(float distance) { m_CameraProps->m_RenderDistance = distance; }
		inline float GetFOV() const { return m_CameraProps->m_FOV; }
		inline void SetFOV(float fov) { m_CameraProps->m_FOV = fov; }
		inline CameraType GetCameraType() const { return m_CameraProps->m_CameraType; }
	
	private:
		CameraProperties* m_CameraProps;
	};
}