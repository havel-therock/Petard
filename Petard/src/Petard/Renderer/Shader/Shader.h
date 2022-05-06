#pragma once
#include "pdpch.h"

#include "glm/glm.hpp"

namespace Petard {

	class Shader
	{
	public:
		Shader(std::unordered_map<unsigned int, const char*> ShaderSet);
		~Shader();

		void Bind() const;
		void Unbind() const;
		
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		unsigned int m_ShaderProgramID;

		std::string LoadShaderSource(const std::string& pathToShader);
	};
}
