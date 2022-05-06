#pragma once
#include "CameraProperties.h"
#include "EngineCamera.h"

// TO DO include aspect ratio of window
// right now objects are being streched according to range of window. Meaning square will be rendered corerectly
// only if window has an aspect ratio of 1.0 (window itself is a square)
namespace Petard {

	class OrtographicCamera : public EngineCamera
	{
	public:
		OrtographicCamera(CameraProperties* cameraProperties);
		//inline const glm::vec3& GetPosition() const { return m_CameraProps->m_Position; }
		//void SetPosition(const glm::vec3& position) { m_CameraProps->m_Position = position; RecalculateViewMatrix(); }
		// move RecalucalteFunction to OnUpdate()/ OnRender() ? 
		// should recalculate this matrix at the end of each onUpdate (once per frame)

		//inline const  glm::vec3& GetRotation() const { return m_CameraProps->m_Rotation; }
		//void SetRotation(const glm::vec3& rotation) { m_CameraProps->m_Rotation = rotation; RecalculateViewMatrix(); }

		inline const glm::mat4& GetProjectionMatrix() const { return m_CameraProps->m_ProjectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return m_CameraProps->m_ViewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return m_CameraProps->m_ViewProjectionMatrix; }
	
		//important
		// inline virtual UserCamera& GetCamera() const { return *m_UserCamera; }

	// can it be private	
		void RecalculateViewMatrix();
		void RecalculateProjectionMatrix();
	// rewrite to use CameraProperties
	private:
		CameraProperties* m_CameraProps;

		// std::unique_ptr<UserCamera> m_UserCamera; // what do you expose to the user;

		// glm::vec3 m_Position; // quaternions chage to vec4 ? 

		// glm::mat4 m_ProjectionMatrix;
		// glm::mat4 m_ViewMatrix;
		// glm::mat4 m_ViewProjectionMatrix; // cache of Projection * View matrices

		// float m_Rotation; // rotation along z-axxis, as orthographic camer should be used for 2D.
		
	};
}