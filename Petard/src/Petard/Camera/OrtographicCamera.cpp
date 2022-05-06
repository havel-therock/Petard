#include "pdpch.h"
#include "OrtographicCamera.h"
#include "Petard/Application.h" 

#include <glm/gtc/matrix_transform.hpp>

namespace Petard {

	OrtographicCamera::OrtographicCamera(CameraProperties* cameraProperties)
		// : m_ProjectionMatrix(glm::ortho(left, right, bottom, top, 0.1f, 100.0f)), m_ViewMatrix(1.0f), m_Rotation(0.0f)
		: m_CameraProps(cameraProperties)
	{
		// for now hardcoded then get boundaries form camera properties
		m_CameraProps->m_ProjectionMatrix = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, m_CameraProps->m_RenderDistance);
		m_CameraProps->m_ViewProjectionMatrix = m_CameraProps->m_ProjectionMatrix * m_CameraProps->m_ViewMatrix;
	}
	void OrtographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_CameraProps->m_Position) * glm::rotate(glm::mat4(1.0f), glm::radians(m_CameraProps->m_Rotation.z), glm::vec3(0, 0, 1));
		// invert matrix cause we have to move whole scene opposite to the direction of camera move
		m_CameraProps->m_ViewMatrix = glm::inverse(transform);
		m_CameraProps->m_ViewProjectionMatrix = m_CameraProps->m_ProjectionMatrix * m_CameraProps->m_ViewMatrix; // this order because opengl is column major
	}

	void OrtographicCamera::RecalculateProjectionMatrix() {
		// left, right
		// float width = static_cast<float>(Application::Get().GetWindow().GetWidth());
		// float height = static_cast<float>(Application::Get().GetWindow().GetWidth());
		// float aspect = height == 0 ? 1 : width/height

		// zoomIn/Out just change ortho boundaries down/up
		m_CameraProps->m_ProjectionMatrix = glm::ortho(-1.0f * m_CameraProps->m_Zoom, 1.0f, -1.0f, 1.0f, 0.1f, m_CameraProps->m_RenderDistance);
	}

	// Recalucalte Vieprojection

	// Recalculate All 
}
