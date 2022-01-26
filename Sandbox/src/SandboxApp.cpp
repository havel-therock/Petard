#include <Petard.h>

#include <iostream>


class SandboxApp : public Petard::Application
{
public:
	SandboxApp() 
	{
	}

	~SandboxApp()
	{

	}

};

Petard::Application* Petard::CreateApplication()
{
	return new SandboxApp();
}