#include "GameLayer.h"
#include <Petard.h>

#include <memory>

GameLayer::GameLayer()
	: Layer("GameLayer") 
	{
		// m_SceneManager = Petard::SceneManager(); // move to engine (class Layer)
	}


void GameLayer::OnAttach()
{
	// consturcte Level hierarchy;
	// Scene
	// m_RootScene = std::make_shared<Petard::SceneNode>(Level("Level_1"));
	// m_RootScene.LoadScene();
	// SetCamera();
	// Submit trianlg e and square to the SceneGraph
	SetCamera(Petard::CameraType::PERSPECTIVE);
	LoadLevel();
}

void GameLayer::OnDetach()
{

}


void GameLayer::OnUpdate(/*Petard::Timestep ts*/) // deltatime time between frames so the movemnt would be independant from frame rate
{
	if (Petard::Input::IsKeyPressed(PD_KEY_DOWN))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ -5.0,0.0,0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_UP))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ 5.0,0.0,0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_RIGHT))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ 0.0,-5.0,0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_LEFT))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ 0.0,5.0,0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_E))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ 0.0,0.0,5.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_Q))
	{
		GetCamera().SetRotation(GetCamera().GetRotation() + glm::vec3({ 0.0,0.0,-5.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_W))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({0.0, 0.0, -0.1}));
	}
	
	if (Petard::Input::IsKeyPressed(PD_KEY_S))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({ 0.0, 0.0, 0.1}));
	}
	
	if (Petard::Input::IsKeyPressed(PD_KEY_A))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({ -0.1, 0.0, 0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_D))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({ 0.1, 0.0, 0.0 }));
	}
	
	if (Petard::Input::IsKeyPressed(PD_KEY_SPACE))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({ 0.0, 0.1, 0.0 }));
	}

	if (Petard::Input::IsKeyPressed(PD_KEY_LEFT_SHIFT))
	{
		GetCamera().SetPosition(GetCamera().GetPosition() + glm::vec3({ 0.0, -0.1, 0.0 }));
	}

	PD_INFO("Camera position: x:{0}, y:{1}, z:{2}", GetCamera().GetPosition().x, GetCamera().GetPosition().y, GetCamera().GetPosition().z);

	// m_renderQueue is being constructed every frame automaticly 
	// based on SceneGraph
	
	// GetPlayer();
	// GetCamera()-> if PD_ARROW_UP == PRESSED?
	//		then move camera.UP
	// 
	// 
	// Logic
		// Input handling
	// m_RootScene.OnUpdate(ts);
	// m_Level.GetPlayer().GetPos() m_Level equals root of the scene?
	// Render drop this part?
	// Petard::RenderCommand::SetClearColor({})
	// Petard::RenderCommand::Clear();
	// Petard::Renderer3D::BeginScene(/*camera, light, environment*/);
	// Petard::Renderer3D::Submit();
	// m_RootScene.OnRender();// m_SceneManager.RenderScene(); // RenderScene() change name to OnRender()?
	// m_RenderQueue.Render();
	// Petard::Renderer3D::EndScene(m_RenderQueue);
}

void GameLayer::OnEvent(Petard::Event& event)
{
	// on Event change cameraDetails props
}

void GameLayer::LoadLevel()
{
	// extremly temporary;
	Petard::BufferLayout layout{
		{Petard::ShaderDataType::Float3, "a_Position"},
		{Petard::ShaderDataType::Float4, "a_Color"}
	};
//#######################################################################################	
	{
	Petard::SceneNode Triangle(true);
	Triangle.m_RenderableObject->m_VertexArray = new Petard::VertexArray();
	float verticesTriangle[3 * 7]{
		-0.6f,  -0.25f,  -0.3f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 1
		 0.6f,  -0.25f,  -0.3f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 2
		 0.0f,    0.7f,   0.9f, 0.0f, 0.0f, 1.0f, 1.0f	// stride 3
	};

	/*
	float verticesTriangle[3 * 7]{
		 60.0f,  105.0f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 1
		 360.0f,  300.0f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 2
		 150.0f,    70.0f,   0.0f, 0.0f, 0.0f, 1.0f, 1.0f	// stride 3
	};
	*/
	uint32_t indicesTriangle[3] = { 0, 1, 2 };

	std::shared_ptr<Petard::VertexBuffer> vb = std::make_shared<Petard::VertexBuffer>(verticesTriangle, sizeof(verticesTriangle));
	vb->SetLayout(layout);

	Triangle.m_RenderableObject->m_VertexArray->AddVertexBuffer(vb);

	std::shared_ptr<Petard::IndexBuffer> triangleIB = std::make_shared<Petard::IndexBuffer>(indicesTriangle, sizeof(indicesTriangle) / sizeof(uint32_t));
	Triangle.m_RenderableObject->m_VertexArray->SetIndexBuffer(triangleIB);

	// AddToScene(Triangle);
	}
//#######################################################################################
	{
	Petard::SceneNode Deltoid(true);
	Deltoid.m_RenderableObject->m_VertexArray = new Petard::VertexArray();

	float vertices[4 * 7]{
		-0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 1
		 0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 2
		 0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 3
		 0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f		// stride 4
	};
	uint32_t indices[6] = { 0, 1, 2, 0, 1, 3 };

	std::shared_ptr<Petard::VertexBuffer> vbDeltoid = std::make_shared<Petard::VertexBuffer>(vertices, sizeof(vertices));
	vbDeltoid->SetLayout(layout);

	Deltoid.m_RenderableObject->m_VertexArray->AddVertexBuffer(vbDeltoid);
	std::shared_ptr<Petard::IndexBuffer> deltoidIB = std::make_shared<Petard::IndexBuffer>(indices, sizeof(indices) / sizeof(uint32_t));
	Deltoid.m_RenderableObject->m_VertexArray->SetIndexBuffer(deltoidIB);

	// AddToScene(Deltoid);
	}
//#######################################################################################
//FLOOR
	{
	Petard::SceneNode Floor(true);
	Floor.m_RenderableObject->m_VertexArray = new Petard::VertexArray();

	float verticesFloor[4 * 7]{
		-10.0f,  -10.0f,  -10.0f,  0.7f, 0.1f, 0.1f, 1.0f,	// stride 1
		 10.0f,  -10.0f,  -10.0f,  0.1f, 0.7f, 0.1f, 1.0f,	// stride 2
		-10.0f,  10.0f,    -2.0f,   0.1f, 0.1f, 0.7f, 1.0f,	// stride 3
		 10.0f,  10.0f,    -2.0f,   0.1f, 0.1f, 0.1f, 1.0f		// stride 4
	};
	uint32_t indicesFloor[6] = { 0, 1, 2, 2, 1, 3 };

	std::shared_ptr<Petard::VertexBuffer> vbFloor = std::make_shared<Petard::VertexBuffer>(verticesFloor, sizeof(verticesFloor));
	vbFloor->SetLayout(layout);

	Floor.m_RenderableObject->m_VertexArray->AddVertexBuffer(vbFloor);
	std::shared_ptr<Petard::IndexBuffer> FloorIB = std::make_shared<Petard::IndexBuffer>(indicesFloor, sizeof(indicesFloor) / sizeof(uint32_t));
	Floor.m_RenderableObject->m_VertexArray->SetIndexBuffer(FloorIB);

	AddToScene(Floor);
	}
	//#######################################################################################
	Petard::Cube* cube = new Petard::Cube();
	
	std::shared_ptr<Petard::VertexBuffer> vbCube = std::make_shared<Petard::VertexBuffer>(cube->vertices, sizeof(cube->vertices));
	vbCube->SetLayout(layout);

	cube->m_RenderableObject->m_VertexArray->AddVertexBuffer(vbCube);
	std::shared_ptr<Petard::IndexBuffer> CubeIB = std::make_shared<Petard::IndexBuffer>(cube->indices, sizeof(cube->indices) / sizeof(uint32_t));
	cube->m_RenderableObject->m_VertexArray->SetIndexBuffer(CubeIB);

	AddToScene(*cube);
	

}
