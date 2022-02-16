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
		glGenVertexArrays(1, &m_VertexArray); // this generate name
		glBindVertexArray(m_VertexArray); // this activates name and all data from VertexBuffers and index buffers will be refered through this name.
										  // vertexarray (object) it is just name that OPENGL uses to get to data
										// 1. creat vertexarray 2. bind it 3. pass data (data is always passe to vertex array which is curently binded). 4. Repeat
										// so tu render everythink just (bind vertexx array then draw, bind next vertex array draw again)
		
		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 4] = {
			-0.5f, 0.0f, 0.0f,		// stride 1
			0.5f, 0.0f, 0.0f,	    // stride 2
			0.0f, 0.5f, 0.0f,       // stride 3
			0.0f, -0.5f, 0.0f
		};

		// load data to GL_ARRAY_BUFFER ( == vertex buffer / buffer of data  )
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // upload data to GPU

		// tell opengl what layout we passed to buffer
		// tell opengl we can start outrr data at index 0
		glEnableVertexAttribArray(0); // can start from 0 ?
		// 1 - the index where our data starts vertex attribute for shader (for e.g. if one data passed but three different attributes per one vertice (e.g. position, color, texture) we need three glVertexAtribPointer() with diff indexes (foirst arguement (0, 1, 2))
		// 2 - how many primitives creates one vertex [1-4]range
		// 3 - what is the type of data
		// 4 - does data should be normalized?
		// 5 - stride - how many bytes between start of each vertices (data) 
		// 6 - offset - what is offset of data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr); // describe uploaded prevously data to OPEN_GL (how it should interpret it on GPU) 
		// create function or macro that auto input all arguments based maybe on the FIXED structure of data? 
		// for example: pos_x, pos_y, pos_z, pos_quaternion? , col_r, col_g, col_b, col_alpha, texture-cords-x, texture-cords-y...
		// pos always float
		// color unsigned int?
		// texture coords ?? Floats?


		//indexBuffer == element buffer
		glGenBuffers(1, &m_IndexBuffer); // Buffer of Indices these are indexes to the data you have passed to ARRAY_BUFFER so in that case vertices
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		unsigned int indices[6] = { 0, 1, 2, 0, 1, 3}; 

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
		std::unordered_map<unsigned int, const char*> shaderList;
		shaderList[GL_VERTEX_SHADER] = "../Petard/res/shaders/vertex/vrtx1.shader";
		shaderList[GL_FRAGMENT_SHADER] = "../Petard/res/shaders/fragment/frg1.shader";
		m_Shader.reset(new Shader(shaderList));
	}
 
	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
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
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			// 2 - how many indices we want to draw
			// 3 - type of data
			// 4 - the data pointer (if null it will takes previoiusly binded indexBuffer data) draw elemets takes data from vertexArray and indeArrey simultanisly to draw
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);


			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

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
