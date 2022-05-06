#pragma once
#include "Buffer.h"
#include "VertexArray.h"

namespace Petard {

	class RenderableObject
	{
	public:	
		RenderableObject()
			: m_ShaderID("default")
		{
			// m_VertexArray = std::unique_ptr<VertexArray>(new VertexArray());
			m_VertexArray = new VertexArray();
		}
		
		
		// RenderableObject(const RenderableObject& other) = default;
		/*
			: m_ShaderID(other.m_ShaderID) {}
		*/
		
		virtual ~RenderableObject() {};

		void SetShaderID() {};
		
		std::string m_ShaderID;
		std::unordered_map<unsigned int, const char*> shaderList;
		// std::unique_ptr<VertexArray> m_VertexArray;
		VertexArray* m_VertexArray;

		
		// shaderList[GL_VERTEX_SHADER] = "../Petard/res/shaders/vertex/vrtx1.shader";
		// shaderList[GL_FRAGMENT_SHADER] = "../Petard/res/shaders/fragment/frg1.shader";
		/*
		m_VertexArray;
		m_Texture;
		m_Normals;
		m_Transform;
		m_Uniforms;
		DYNAMIC/STATIC DRAW based on count change
		*/
	};
}