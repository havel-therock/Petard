#pragma once

namespace Petard {
	
	class VertexBuffer 
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static VertexBuffer* Create();
	};

	class IndexBuffer {
		int a;
	};
}
