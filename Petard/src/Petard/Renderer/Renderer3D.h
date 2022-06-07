#pragma once
#include "Petard/Renderer/Buffer.h" 
#include "RenderQueue.h"
#include "RenderableObject.h"

#include "glad/glad.h"

namespace Petard {

	class Renderer3D 
	{
	public:
		static void Init();
		static void Shutdown();

		// hmmm? to dump
		static void BeginScene(/*camera, lighting, env*/);
		static void EndScene(std::shared_ptr<RenderQueue> renderQueue);
		
		static void Render(RenderableObject& renderableObject, unsigned int renderMode = GL_TRIANGLES);
		static void BindAndRender(RenderableObject renderableObject);

		/* Submit renderable object to the render queue */
		// static void Submit(RenderQueue renderQueue, RenderableObject& renderableObject);
		// static void Submit(RenderQueue ,const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
		

		// Implement 3D Primitives: 
		// * cube
		// * pyramid
		// * tetrahedrons
		// * sphere
		// * roller
		// * cone
		
		
		// Implement 2D Primitives:
		// 
		// static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		// static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, const glm::vec4& color);

	};
}