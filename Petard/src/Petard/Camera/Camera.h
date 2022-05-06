#pragma once
#include "UserCamera.h"
#include "EngineCamera.h"
#include "CameraProperties.h"

namespace Petard {

	class Camera // final 
	{
	public:
		Camera();
		inline EngineCamera& GetEngineCamera() const { return *m_EngineCamera; }
		inline UserCamera& GetUserCamera() const { return *m_UserCamera; }
		inline CameraProperties& GetCameraProperties() const { return *m_CameraProperties; }
		
		void SetEngineCamera(CameraType cameraType);

	private:
		std::unique_ptr<CameraProperties> m_CameraProperties;
		std::unique_ptr<EngineCamera> m_EngineCamera;
		std::unique_ptr<UserCamera> m_UserCamera;
	};
}