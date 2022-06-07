#include "pdpch.h"
#include "RenderableObject.h"

#include "glm/gtc/matrix_transform.hpp"


namespace Petard {

	void RenderableObject::RecalculateModelMatrix()
	{
		// order is first scale then rotate and translate at the end.
		// it is this order -->  translate * rotate * scale
		// because matrix multiplications starts from the right handsigt not from the left.
		// end equivalent of this multiplication in this order using transforms is here:
		glm::mat4 newModelMatrix = glm::translate(glm::mat4(1.0f), m_Position);
		newModelMatrix = glm::rotate(newModelMatrix, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		newModelMatrix = glm::rotate(newModelMatrix, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		newModelMatrix = glm::rotate(newModelMatrix, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		newModelMatrix = glm::scale(newModelMatrix, glm::vec3(m_Scale));
		m_ModelMatrix = newModelMatrix;
	}
}
 