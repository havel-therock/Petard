#pragma once

#include "Petard/Renderer/Buffer.h" 
#include "glm/glm.hpp"

namespace Petard {

	class Renderer3D 
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(/*camera, lighting, env*/);
		static void EndScene();
		
		// static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
		
		// Primitives
		//
		// static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		// static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const glm::vec4& color);
	};
}