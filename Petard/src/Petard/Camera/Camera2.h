#pragma once
#include "glm/glm.hpp"

namespace Petard {
	/*
	enum class CameraType
	{
		NONE = 0, 
		ORTHOGONAL,
		PERSPECTIVE,
		IZOMETRIC
		//...
	};
	
	struct CameraProperties 
	{
		// ORTHOGONAL, PERSPECTIVE
		CameraType m_CameraType;
		glm::vec3 m_Position; // quaternions chage to vec4 ? 
		glm::vec3 m_Rotation;
		float m_RenderDistance;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position;
		
		// ORTHOGONAL
		float m_Zoom;

		// PERSPECTIVE
		float m_FOV; // FOV as angle in degrees for perspective is just FOV for orthographic it is width of frustum

	};
	*/

	// Interface for cameras:
	class Camera
	{
	public:
		virtual ~Camera() {};

		virtual inline const glm::vec3& GetPosition() const { return m_Position; };
		virtual inline void SetPosition(const glm::vec3& position) { m_Position = position; }
		virtual inline const glm::vec3& GetRotation() const { return m_Rotation; }
		virtual inline void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; }
		// virtual const float GetZoom() const { return 1.0f; } // = 0;
		// virtual void SetZoom(float zoom) {} // = 0;
		
		// interface for perspective camera
		virtual inline unsigned int GetFOV() const { return m_FOV; }
		virtual inline void SetFOV(float fov) { m_FOV = fov; }
		
		virtual void SetRenderDistance(float distance) {}

		// interface for perspective camera
		virtual const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		virtual const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		virtual const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		virtual CameraType GetCameraType() { return m_CameraType; }
		virtual UserCamera& GetCamera() const = 0;
	
	private:
		/*
		union m_UserCamera
		{

		};
		*/
	/*
	protected:
		glm::vec3 m_Position; // quaternions chage to vec4 ? 
		glm::vec3 m_Rotation;
		float m_Zoom;
		float m_FOV; // FOV as angle in degrees for perspective is just FOV for orthographic it is width of frustum
		
		CameraType m_CameraType;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix; // cache of Projection * View matrices
		
		void RecalculateViewMatrix() {};
	*/
	};
}