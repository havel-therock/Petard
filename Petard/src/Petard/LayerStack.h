#pragma once

#include "Petard/Core.h"
#include "Layer.h"

#include <vector>

namespace Petard {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);
		
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		//divider between layers and overlays vec -> < l,l,l,l, iterator, ol, ol, ol, ol>
		std::vector<Layer*>::iterator m_LayerInsert;

	};
}