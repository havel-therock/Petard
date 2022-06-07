#pragma once
#include "Buffer.h"
#include "VertexArray.h"
#include "glm/glm.hpp"

namespace Petard {

	class RenderableObject
	{
	public:	
		RenderableObject()
			: m_ShaderID("default"), m_Position(glm::vec3(0.0f)), m_Scale(1.0f), m_Rotation(glm::vec3(0.0f)), m_ModelMatrix(glm::mat4(1.0f))
		{
			// m_VertexArray = std::unique_ptr<VertexArray>(new VertexArray());
			m_VertexArray = new VertexArray();
			// m_ModelMatrix = glm::mat4
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
		VertexArray* m_VertexArray; //absoluth positions, relations of vertices

		// position on the map
		glm::vec3 m_Position;
		float m_Scale; // 0.0 < scale < 100.0
		glm::vec3 m_Rotation;

		glm::mat4 m_ModelMatrix; // ( build from position in the renderObject... not in vertexObject ) /// build from all transposotioins (rotation, scale translation)  
		// glm::mat4 m_
		
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
		//float3 m_Position // model matrix uniform is constructed based on this. position in the GAME world
		// m_scale for sure
	//private:
		void RecalculateModelMatrix();
	};
}