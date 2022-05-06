#include "pdpch.h"
#include "Camera.h"
#include "OrtographicCamera.h"
#include "PerspectiveCamera.h"

namespace Petard {

    Camera::Camera()
    {
		m_CameraProperties = std::make_unique<CameraProperties>();
		m_EngineCamera = std::make_unique<OrtographicCamera>(m_CameraProperties.get());
		m_UserCamera = std::make_unique<UserCamera>(m_CameraProperties.get());
    }

	void Camera::SetEngineCamera(CameraType cameraType)
	{
		m_CameraProperties->m_CameraType = cameraType;
		switch (cameraType)
		{
		case CameraType::ORTHOGONAL:
			m_EngineCamera.reset(new OrtographicCamera(m_CameraProperties.get()));
			break;
		case CameraType::PERSPECTIVE:
			m_EngineCamera.reset(new PerspectiveCamera(m_CameraProperties.get()));
			break;
		default:
			m_EngineCamera.reset(new OrtographicCamera(m_CameraProperties.get()));
			break;
		}
	}
}