#include "pdpch.h"
#include "RenderQueue.h"

#include "Renderer3D.h"
#include "Shader/Shader.h"
#include "glad/glad.h"

namespace Petard {

	RenderQueue::RenderQueue()
		: m_Camera(nullptr)
	{
		std::unordered_map<unsigned int, const char*> shaderList;
		shaderList[GL_VERTEX_SHADER] = "../Petard/res/shaders/vertex/vrtx1.shader";
		shaderList[GL_FRAGMENT_SHADER] = "../Petard/res/shaders/fragment/frg1.shader";
		m_ShadersList.insert({ "default", std::make_unique<Shader>(shaderList) });
	}

	void RenderQueue::Render(/*enum ST/MT*/)
	{
		//switch(enum ST/MT)
		// callSTRender()
		// or
		// callMTRender()
		// check flags for MT/ST (multithreaded/singlethreaded) rendering
		// as of now focuse on all single thread
		RenderST();
	}

	void RenderQueue::ClearShaderList()
	{
		// TO DO: leave the default shader?
	}

	void RenderQueue::ClearRenderQueue()
	{
		m_RenderQueue.clear();
	}

	void RenderQueue::Clear()
	{
		ClearRenderQueue();
		ClearShaderList();
	}

	void RenderQueue::RenderST()
	{
		OptimizeRenderQueueST();

		// basic super slow method just render passed vertexArray
		// 2D way objects are rendered in order they appear in renderqueue
		for (auto& object : m_RenderQueue) {
			// add dynamic compiling and appending to shaderList new shaders pointed by objects
			// add checking for existance of shader in shader list
			
			if (m_ShadersList.count(object.m_ShaderID) == 0)
				m_ShadersList.insert({ object.m_ShaderID, std::make_unique<Shader>(object.shaderList) });

			m_ShadersList[object.m_ShaderID]->Bind();
			if (m_Camera != nullptr)
			{
				m_ShadersList[object.m_ShaderID]->UploadUniformMat4("u_ViewProjection", m_Camera->GetViewProjectionMatrix());
				// m_ShadersList[object.m_ShaderID]->UploadUniformMat4("u_Model", object.GetModelMatrix());
			}
			else 
			{
				m_ShadersList[object.m_ShaderID]->UploadUniformMat4("u_ViewProjection", glm::mat4(1.0f));
				// m_ShadersList[object.m_ShaderID]->UploadUniformMat4("u_Model", glm::mat4(1.0f));
			}
			// Upload object uniforms
			m_ShadersList[object.m_ShaderID]->UploadUniformMat4("u_Model", object.m_ModelMatrix);

			// bind vertex array from object? or do it within R3D::Render() function
			object.m_VertexArray->Bind();
			Renderer3D::Render(object);
		}
		// possible upgrade to group object by shaders
		// and only bind/compile it once
	}

	void RenderQueue::RenderMT()
	{
		OptimizeRenderQueueMT();
	}

	void RenderQueue::OptimizeRenderQueueST()
	{
		// group rendering objects by the same shader ond only compile/bind it once?
		// put in cache for another updates//
	}
	
	void RenderQueue::OptimizeRenderQueueMT()
	{
	}


}