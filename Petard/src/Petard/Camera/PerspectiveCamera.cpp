#include "pdpch.h"
#include "PerspectiveCamera.h"

#include "Petard/Application.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace Petard {

	PerspectiveCamera::PerspectiveCamera(CameraProperties* cameraProperties)
		: m_CameraProps(cameraProperties)
	{
		// really tmp
		float width = static_cast<float>(Application::Get().GetWindow().GetWidth());
		float height = static_cast<float>(Application::Get().GetWindow().GetWidth());
		float aspect = height == 0 ? 1 : width / height;
		// end of tmp move these to CameraProps
		m_CameraProps->m_ProjectionMatrix = glm::perspective(m_CameraProps->m_FOV, aspect, 0.1f, m_CameraProps->m_RenderDistance);
		m_CameraProps->m_ViewProjectionMatrix = m_CameraProps->m_ProjectionMatrix * m_CameraProps->m_ViewMatrix;
	}
	void PerspectiveCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_CameraProps->m_Position) * glm::rotate(glm::mat4(1.0f), glm::radians(m_CameraProps->m_Rotation.z), glm::vec3(0, 0, 1));
		transform = transform * glm::rotate(glm::mat4(1.0f), glm::radians(m_CameraProps->m_Rotation.y), glm::vec3(0, 1, 0));
		transform = transform * glm::rotate(glm::mat4(1.0f), glm::radians(m_CameraProps->m_Rotation.x), glm::vec3(1, 0, 0));
		// invert matrix cause we have to move whole scene opposite to the direction of camera move
		m_CameraProps->m_ViewMatrix = glm::inverse(transform);
		m_CameraProps->m_ViewProjectionMatrix = m_CameraProps->m_ProjectionMatrix * m_CameraProps->m_ViewMatrix; // this order because opengl is column major
	}
}