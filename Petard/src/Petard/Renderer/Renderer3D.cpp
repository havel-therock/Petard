#include "pdpch.h"
#include "Renderer3D.h"


namespace Petard {

	void Renderer3D::Init()
	{
	}
	
	void Renderer3D::Shutdown()
	{
	}
	
	void Renderer3D::BeginScene()
	{
	}
	
	void Renderer3D::EndScene()
	{
		// optimize
		// and flush/render
	}

	/*
	// this function is very important it is performing the draw call!!!!!
	void Renderer3D::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}*/
}
