#include "pdpch.h"
#include "Renderer3D.h"

#include "glad/glad.h"

namespace Petard {

	void Renderer3D::Init()
	{
	}
	
	void Renderer3D::Shutdown()
	{
	}
	
	void Renderer3D::BeginScene(/*camera, light, environment*/)
	{
	}
	
	void Renderer3D::EndScene(std::shared_ptr<RenderQueue> RenderQueue)
	{
		// optimize
		// and flush/render
		RenderQueue->Render();
	}

	void Renderer3D::Render(RenderableObject& renderableObject)
	{
		glDrawElements(GL_TRIANGLES, renderableObject.m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer3D::BindAndRender(RenderableObject renderableObject)
	{
		// NOT TO USE RIGHT NOW NOT included SHADER BINIDNG() 
		// somehow bind shader? compile shader fram object.m_Shader map of paths then bind it
		renderableObject.m_VertexArray->Bind();
		glDrawElements(GL_TRIANGLES, renderableObject.m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}


	// submit pushes to renderqueue

	// render render(vertexArray, shader, transform?)

	// drawQuad();

	// drawTriangle();

	/*
	// this function is very important it is performing the draw call!!!!!
	void Renderer3D::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
	
	
	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
	{
		uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
	*/


}
