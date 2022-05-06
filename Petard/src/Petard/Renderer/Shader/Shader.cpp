#include "pdpch.h"
#include "Shader.h"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

namespace Petard {

	/* allowed values for first element: 
	GL_VERTEX_SHADER,
	GL_TESS_CONTROL_SHADER,
	GL_TESS_EVALUATION_SHADER,
	GL_GEOMETRY_SHADER,
	GL_FRAGMENT_SHADER,
	GL_COMPUTE_SHADER
	*/
	Shader::Shader(std::unordered_map<unsigned int, const char*> ShaderSet)
	{
		std::vector<GLuint> shaderList;
		for (auto& it : ShaderSet)
		{
			// Create handle for shader
			GLuint shader = glCreateShader(it.first);
			shaderList.push_back(shader);
			// Load shader from file
			std::string string_source = LoadShaderSource(it.second); // to optimizess
			const GLchar* shaderSource = string_source.c_str();
			// Send shader source code to GL
			glShaderSource(shader, 1, &shaderSource, 0);
			// Compile shader
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength); // to change vector not optimal
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
				// We don't need shaders anymore.
				for (auto& shader_handle : shaderList)
					glDeleteShader(shader_handle);
				
				// Use the infoLog as you see fit.
				PD_CORE_ERROR("Shader '{0}' compilation error: {1}", it.second, infoLog.data());
				PD_CORE_ASSERT(false, "Shader compilation error");
				return;
			}
		}

		// Get a program object.
		m_ShaderProgramID = glCreateProgram();
		// attach all compiled shaders
		for (auto& shader_handle : shaderList)
			glAttachShader(m_ShaderProgramID, shader_handle);

		// Link our program
		glLinkProgram(m_ShaderProgramID);

		GLint isLinked = 0;
		glGetProgramiv(m_ShaderProgramID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ShaderProgramID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength); // to change
			glGetProgramInfoLog(m_ShaderProgramID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(m_ShaderProgramID);
			// Don't leak shaders either.
			for (auto& shader_handle : shaderList)
				glDeleteShader(shader_handle);

			// Use the infoLog as you see fit.
			PD_CORE_ERROR("Shader linking error: {1}", infoLog.data());
			PD_CORE_ASSERT(false, "Shader linking error");
			return;
		}

		for (auto& shader_handle : shaderList)
		{
			glDetachShader(m_ShaderProgramID, shader_handle);
			//glDeleteShader(shader_handle);	// don't know if neccesary maybe better to keep shaders here
		}
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderProgramID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_ShaderProgramID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = glGetUniformLocation(m_ShaderProgramID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	std::string Shader::LoadShaderSource(const std::string& pathToShader)
	{	
		std::ifstream stream(pathToShader);
		std::string line;
		std::string Shader = "";
		while (getline(stream, line))
		{
			Shader += (line + '\n');
		}
		stream.close();
		std::cout << Shader;
		return Shader;
	}

}