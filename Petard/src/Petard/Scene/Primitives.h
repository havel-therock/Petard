#pragma once
#include "SceneNode.h"

namespace Petard {
	//2D
	
	
	//3D
	class Cube : public SceneNode
	{
	public:
		Cube()
			: SceneNode(true, "Cube") {
			m_RenderableObject->m_VertexArray = new VertexArray();
		}
		
		float vertices[8 * 7] = { // 7 is hardcoded but is dependant on VertexBufferLayout;
			0.0f,  0.0f,  0.0f,		0.7f, 0.0f, 1.0f, 1.0f,	// stride 1
			0.0f,  1.0f,  0.0f,		0.7f, 0.0f, 1.0f, 1.0f,
			1.0f,  0.0f,  0.0f,		0.7f, 0.7f, 1.0f, 1.0f,	// stride 2
			1.0f,  1.0f,  0.0f,		0.7f, 0.7f, 1.0f, 1.0f,	// stride 3


			0.0f,  0.0f, -1.0f,		0.0f, 0.0f, 0.0f, 1.0f,	// stride 1
			0.0f,  1.0f, -1.0f,		0.0f, 0.0f, 0.0f, 1.0f,
			1.0f,  0.0f, -1.0f,		0.0f, 0.7f, 0.3f, 1.0f,	// stride 2
			1.0f,  1.0f, -1.0f,		0.0f, 0.7f, 0.3f, 1.0f	// stride 3
		};

		uint32_t indices[36] = { 
			0, 1, 3,
			0, 2, 3,

			0, 1, 7,
			0, 6, 7,

			4, 5, 7,
			4, 6, 7,

			2, 3 ,7,
			2, 6 ,7,

			0, 2, 6,
			0, 6, 4, 

			1, 3, 7,
			1, 7, 5 
		};



		/*
		float verticesTriangle[3 * 7]{
			 60.0f,  105.0f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 1
			 360.0f,  300.0f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	// stride 2
			 150.0f,    70.0f,   0.0f, 0.0f, 0.0f, 1.0f, 1.0f	// stride 3
		};
		*/
		/*
		uint32_t indicesTriangle[3] = { 0, 1, 2 };

		std::shared_ptr<Petard::VertexBuffer> vb = std::make_shared<Petard::VertexBuffer>(verticesTriangle, sizeof(verticesTriangle));
		vb->SetLayout(layout);

		Triangle.m_RenderableObject->m_VertexArray->AddVertexBuffer(vb);

		std::shared_ptr<Petard::IndexBuffer> triangleIB = std::make_shared<Petard::IndexBuffer>(indicesTriangle, sizeof(indicesTriangle) / sizeof(uint32_t));
		Triangle.m_RenderableObject->m_VertexArray->SetIndexBuffer(triangleIB);
		*/
	};

	// class Cone
}