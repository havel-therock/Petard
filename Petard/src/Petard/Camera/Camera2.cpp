#include "pdpch.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Petard {

	void Camera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position); 
		transform = glm::rotate(transform, glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
		transform = glm::rotate(transform, glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
		transform  = glm::rotate(transform, glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));
		// transform = glm::scale(transform, glm::vec3(0.5, 0.5, 0.5));  

		// invert matrix - because move of the camera is just moving the whole world in inverted directions. 
		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix; // this order because opengl is column major
	}
}