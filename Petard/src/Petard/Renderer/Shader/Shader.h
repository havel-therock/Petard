#pragma once
#include "pdpch.h"


namespace Petard {

	class Shader
	{
	public:
		Shader(std::unordered_map<unsigned int, const char*> ShaderSet);
		~Shader();

		void Bind() const;
		void Unbind() const;
	
	private:
		unsigned int m_ShaderProgramID;

		std::string LoadShaderSource(const std::string& pathToShader);
	};

}
