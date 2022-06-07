#include "pdpch.h"
#include "Application.h"

#include "Petard/Log.h"

#include "Input.h"
#include "glad_glfw.h"

namespace Petard {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1) 

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PD_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		//push overlay ImGuiLayer()

		// Vertex Array
		// Vertex Buffer
		// Index Buffer
		// Shader
			// vertex shader
			// fragmetn shader
			// code that compiles the shader

		//vertexArray It is just a NAME_ID (we don't know what is the actual name vaslue but openGL does)
		//glGenVertexArrays(1, &m_VertexArray); // this generate name
		//glBindVertexArray(m_VertexArray); // this activates name and all data from VertexBuffers and index buffers will be refered through this name.
										  // vertexarray (object) it is just name that OPENGL uses to get to data
										// 1. creat vertexarray 2. bind it 3. pass data (data is always passe to vertex array which is curently binded). 4. Repeat
										// so tu render everythink just (bind vertexx array then draw, bind next vertex array draw again)
		/*
		m_VertexArray.reset(new VertexArray());

		float vertices[4 * 7] {
			-0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 1
			 0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 2
			 0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// stride 3
			 0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f		// stride 4
		};

		m_VertexBuffer.reset(new VertexBuffer(vertices, sizeof(vertices)));
		// glGenBuffers(1, &m_VertexBuffer);
		// glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
		// load data to GL_ARRAY_BUFFER ( == vertex buffer / buffer of data  )
		// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // upload data to GPU
		
		BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position"},
			{ ShaderDataType::Float4, "a_Color"}
		};
			
		m_VertexBuffer->SetLayout(layout);
			

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);
		// tell opengl what layout we passed to buffer
		// tell opengl we can start our data at index 0
		// glEnableVertexAttribArray(0); // can start from 0 ? <enable location in shader>
		// 1 - location in shader the index where our data starts vertex attribute for shader (for e.g. if one data passed but three different attributes per one vertice (e.g. position, color, texture) we need three glVertexAtribPointer() with diff indexes (foirst arguement (0, 1, 2))
		// 2 - how many primitives creates one vertex [1-4]range
		// 3 - what is the type of data
		// 4 - does data should be normalized? for example supplying an int and normalizinig it to float
		// 5 - stride - how many bytes between start of each vertices (data) 
		// 6 - offset - what is offset of data
		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr); // describe uploaded prevously data to OPEN_GL (how it should interpret it on GPU) 
		// create function or macro that auto input all arguments based maybe on the FIXED structure of data? 
		// for example: pos_x, pos_y, pos_z, pos_quaternion? , col_r, col_g, col_b, col_alpha, texture-cords-x, texture-cords-y...
		// pos always float
		// color unsigned int?
		// texture coords ?? Floats?


		//indexBuffer == element buffer
		// glGenBuffers(1, &m_IndexBuffer); // Buffer of Indices these are indexes to the data you have passed to ARRAY_BUFFER so in that case vertices
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		uint32_t indices[6] = { 0, 1, 2, 0, 1, 3};
		m_IndexBuffer.reset(new IndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
		// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		m_SquareVA.reset(new VertexArray());

		float verticesSQ[3 * 7]{
			-0.6f,  -0.25f,  -0.3f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 1
			 0.6f,  -0.25f,  -0.3f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 2
			 0.0f,    0.7f,   0.9f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 3
		};
		uint32_t indicesSQ[3] = { 0, 1, 2 };

		std::shared_ptr<VertexBuffer> squareVB = std::make_shared<VertexBuffer>(verticesSQ, sizeof(verticesSQ));
		squareVB->SetLayout(layout);
		m_SquareVA->AddVertexBuffer(squareVB);
		std::shared_ptr<IndexBuffer> squareIB = std::make_shared<IndexBuffer>(indicesSQ, sizeof(indicesSQ) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);
		*/

		// std::unordered_map<unsigned int, const char*> shaderList;
		// shaderList[GL_VERTEX_SHADER] = "../Petard/res/shaders/vertex/vrtx1.shader";
		// shaderList[GL_FRAGMENT_SHADER] = "../Petard/res/shaders/fragment/frg1.shader";
		// m_Shader.reset(new Shader(shaderList));

		// Enable depth test
		//move this to the LAYER
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		//glDepthFunc(GL_LESS);
		// for alpha belnding
		// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// glEnable(GL_BLEND);


		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	}
 
	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}
	// TO DO POPLAYERS

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			// push this out of application;
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// m_Shader->Bind();

			// m_VertexArray->Bind();
			// 2 - how many indices we want to draw
			// 3 - type of data
			// 4 - the data pointer (if null it will takes previoiusly binded indexBuffer data) draw elemets takes data from vertexArray and indeArrey simultanisly to draw
			// glBindVertexArray(m_VertexArray);
			// glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			// m_SquareVA->Bind();
			// glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	



			for (Layer* layer : m_LayerStack) {
				// layer->activateGLTests()
				// layer->clearBuffer()
				layer->OnUpdate();
				layer->OnRender();
				// layer->deactivateGLTests()
				// __debugbreak(); chechk debug if order of render of layers is correct. Event should go down the stack and renders up the stack
				// get from config on Petard::Init()
			}

			auto [x, y] = Input::GetMousePos();
			// PD_CORE_TRACE("{0}, {1}", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	
}
