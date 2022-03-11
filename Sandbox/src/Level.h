#pragma once
#include "Petard.h"

class Level : public Petard::SceneNode
{
public:
	Level(const std::string IdName);
	void LoadScene();
	
};