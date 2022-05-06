#pragma once
#include "Scene/SceneNode.h"
#include "Renderer/RenderQueue.h"
#include "Petard/Events/Event.h"
#include "Petard/Camera/Camera.h"
#include "Petard/Camera/UserCamera.h"
#include "Petard/Camera/OrtographicCamera.h"


// #define GetCamera() GetCamera(cameraType)

namespace Petard {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() {};

		/* Load recources. */
		virtual void OnAttach() {} /* May be root_scean invisible by default? */
		/* Free resources from memory. */
		virtual void OnDetach() {}
		/* Function called every frame. Main game loop inside this function. */
		virtual void OnUpdate(/* Timestep ts */) {} /* maybe refactor to looks like OnRender function. So update is propagated through sceneNode.OnUpdate() and its child */
		/* Callback function that triggers when Event is generated. */
		virtual void OnEvent(Event& event) {}

	/* make private later as it shouldn't be called by user (should be called after OnUpdate())*/
		/* Based on Scene Graph construct RenderQueue and then render the Queue */
		void OnRender();
	
	/* debug dev functions */
		inline const std::string& GetName() const { return m_DebugName; }
	
		/* user functions */
		// SceneGraph
		void AddToScene(SceneNode childNode);
		SceneNode& GetSceneByName(const std::string& name) {}; // TO DO:

		//Camera move functional camera. speed of camera and any other properties are held in user defined objects
		/*
		const glm::vec3& GetCameraPosition() const;
		void SetCameraPosition(const glm::vec3& position);
		const glm::vec3& GetCameraRotation() const;
		void SetCameraRotation(const glm::vec3& position);
		*/
		
		void SetCamera(CameraType cameraType);
		// inline Camera& GetCamera() const { return *(m_Camera.get()); }
		// GetCamera() returns reference to the m_Camera.userCamera
		inline UserCamera& GetCamera() const { return m_Camera->GetUserCamera(); }

	protected:
		std::string m_DebugName; 

	private:
		std::unique_ptr<SceneNode> m_RootScene;
		std::unique_ptr<RenderQueue> m_RenderQueue;
		std::unique_ptr<Camera> m_Camera;

	};

}