#include "pdpch.h"
#include "Primitives.h"

#include "glad/glad.h" 

namespace Petard {

	Primitive::Primitive(PrimitiveType primitiveType)
		: SceneNode(true, "Primitive-"), m_Precision(5)
	{
		switch (primitiveType)
		{

		case PrimitiveType::NONE:
			PD_CORE_WARN("Primitive type is set to NONE!");
			break;
		
		// 2D ################################################
		case PrimitiveType::TRIANGLE:
			ConstructTriangle();
			break;
		case PrimitiveType::QUAD:
			ConstructQuad();
			break;
		case PrimitiveType::CIRCLE:
			ConstructCircle();
			break;
		
		// 3D ################################################
		case PrimitiveType::CUBE:
			ConstructCube();
			break;
		case PrimitiveType::PYRAMID:
			ConstructPyramid();
			break;
		case PrimitiveType::SPHERE:
			ConstructSphere();
			break;
		
		default:
			PD_CORE_ERROR("Primitive type not recognized!!!");
			break;
		}
		SetCommonSettings();
	}
	
	Primitive::~Primitive()
	{
		
		// delete m_RenderableObject->m_VertexArray; causing error???? in binding vertex array before drawing
		delete m_Vertices;
		delete m_Indices;
		
	}


	void Primitive::ConstructTriangle()
	{
		m_IdName += "Triangle";

		m_VerticesLength = 3 * 7;
		m_Vertices = new float[m_VerticesLength] { // 7 is hardcoded but is dependant on VertexBufferLayout;
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,	// stride 1
			 0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f	// stride 2
		};

		m_IndicesLength = 3;
		m_Indices = new uint32_t[m_IndicesLength]{
			0, 1, 2
		};
	}

	void Primitive::ConstructQuad()
	{
		m_IdName += "Quad";

		m_VerticesLength = 4 * 7;
		m_Vertices = new float[m_VerticesLength] { // 7 is hardcoded but is dependant on VertexBufferLayout;
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,	// stride 1
			 0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, 0.0f,		0.0f, 0.7f, 1.0f, 1.0f,	// stride 2
			-0.5f,  0.5f, 0.0f,		0.0f, 0.7f, 1.0f, 1.0f	// stride 2
		};

		m_IndicesLength = 6;
		m_Indices = new uint32_t[m_IndicesLength]{
			0, 1, 2,
			0, 2, 3
		};
	}

	void Primitive::ConstructCircle()
	{
		m_IdName += "Circle";
		m_VerticesLength = 4 * 7;
		m_Vertices = new float[m_VerticesLength] {
			-1.0f, -1.0f, 0.0f,		1.0f, 1.0f, 1.0f, 1.0f,	// stride 1
			 1.0f, -1.0f, 0.0f,		1.0f, 1.0f, 1.0f, 1.0f,
			 1.0f,  1.0f, 0.0f,		1.0f, 1.0f, 1.0f, 1.0f,	// stride 2
			-1.0f,  1.0f, 0.0f,		1.0f, 1.0f, 1.0f, 1.0f	// stride 2
		};

		m_IndicesLength = 6;
		m_Indices = new uint32_t[m_IndicesLength]{
			0, 1, 2,
			0, 2, 3
		};

		m_RenderableObject->m_ShaderID = "CIRCLE";
		m_RenderableObject->shaderList[GL_VERTEX_SHADER] = "../Petard/res/shaders/vertex/vrtx1.shader";
		m_RenderableObject->shaderList[GL_FRAGMENT_SHADER] = "../Petard/res/shaders/fragment/frgCircle.shader";
	}

	void Primitive::ConstructCube()
	{
		m_IdName += "Cube";
		
		m_VerticesLength = 8 * 7;
		m_Vertices = new float[m_VerticesLength]{ // 7 is hardcoded but is dependant on VertexBufferLayout;
			-0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f, 1.0f,	// stride 1
			 0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, 0.5f,		1.0f, 0.0f, 0.0f, 1.0f,	// stride 2
			-0.5f,  0.5f, 0.5f,		1.0f, 0.0f, 0.0f, 1.0f,	// stride 3

			-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,	// stride 1
			 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,	// stride 2
			-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,	// stride 3
		};

		m_IndicesLength = 36;
		m_Indices = new uint32_t[m_IndicesLength]{
			0, 1, 2,
			0, 2, 3,

			3, 2, 6,
			3, 6, 7,

			4, 5, 6,
			4, 6, 7,

			0, 5, 1,
			0, 5, 4,

			0, 3, 7,
			0, 7, 4,

			1, 2, 6,
			1, 6, 5
		};
	}

	void Primitive::ConstructPyramid()
	{
		m_IdName += "Pyramid";

		m_VerticesLength = 5 * 7;
		m_Vertices = new float[m_VerticesLength] { // 7 is hardcoded but is dependant on VertexBufferLayout;
			-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f, 1.0f,	// stride 1
			 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f, 1.0f,
			 0.0f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f, 1.0f,	// stride 2
			-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,	1.0f, 1.0f,	// stride 3
			 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f, 1.0f,	// stride 1
		};

		m_IndicesLength = 18;
		m_Indices = new uint32_t[m_IndicesLength]{
			0, 1, 2,
			1, 4, 2,
			4, 3, 2,
			3, 0, 2,
			//base
			0, 1, 4,
			0, 4, 3
		};
	}

	void Primitive::ConstructCone()
	{
	}

	void Primitive::ConstructSphere()
	{
	}

	void Primitive::SetCommonSettings()
	{
		Petard::BufferLayout layout{
			{Petard::ShaderDataType::Float3, "a_Position"},
			{Petard::ShaderDataType::Float4, "a_Color"}
		};

		m_RenderableObject->m_VertexArray = new VertexArray();

		std::shared_ptr<Petard::VertexBuffer> vb = std::make_shared<Petard::VertexBuffer>(m_Vertices, sizeof(float)* m_VerticesLength);
		vb->SetLayout(layout);
		m_RenderableObject->m_VertexArray->AddVertexBuffer(vb);

		std::shared_ptr<Petard::IndexBuffer> ib = std::make_shared<Petard::IndexBuffer>(m_Indices, m_IndicesLength);
		m_RenderableObject->m_VertexArray->SetIndexBuffer(ib);
	}

}
