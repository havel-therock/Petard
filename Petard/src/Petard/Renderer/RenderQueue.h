#pragma once
#include "Petard/Camera/Camera.h"
#include "RenderableObject.h"
#include "Shader/Shader.h"

namespace Petard{

	// The Q of renderable objects which you can call a render function on 
	// here you can try optimizing it before draw calls
	// maybe called through SceneManager
	class RenderQueue
	{
	public:
		RenderQueue();
		~RenderQueue() {};
		void Render(/*enum MT/St ?*/);
		void ClearRenderQueue();
		void ClearShaderList();
		void Clear();
		inline void UploadRenderQueue(std::vector<RenderableObject> renderQueue) { m_RenderQueue = renderQueue; }		
		inline void UploadCamera(const EngineCamera* camera) { m_Camera = camera; }
	private:
		// change scene node to renderable object props:
		// shader, vertexArray
		std::vector<RenderableObject> m_RenderQueue; // may need to  be be public
		std::unordered_map<std::string, std::unique_ptr<Shader>> m_ShadersList;
		
		// camera updated every frame
		const EngineCamera* m_Camera;
		// Camera settings,
		// Light settings,
		// Environment settings.


		void RenderST();
		void RenderMT();
		void OptimizeRenderQueueST();
		void OptimizeRenderQueueMT();

		// every shader has a uniqe name:
		// map of <shader_name, shader_program>
		// so Renderable objects has shaders names and paths, if name is not present in the map
		// then compile shader under given name and save it here to the shader_map 
		// private cached shaders or something.
		// Render data that could be reused... maybe state of the vector to not recalculate it each frame. Only appling changes to the moved objects or something
	};
}