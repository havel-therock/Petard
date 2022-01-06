#include <Petard.h>

#include <iostream>

class SandboxApp : public Petard::Application
{
public:
	SandboxApp() 
	{
		std::cout << "SandBoxApp created!";
	}

	~SandboxApp()
	{

	}

};

Petard::Application* Petard::CreateApplication()
{
	return new SandboxApp();
}