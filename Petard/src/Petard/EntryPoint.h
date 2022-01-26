#pragma once

#include "Application.h"


#ifdef PD_PLATFORM_WINDOWS

extern Petard::Application* Petard::CreateApplication();

int main(int argc, char** argv) {
	// not here later
	Petard::Log::Init();
	PD_CORE_WARN("iniitialized");

	auto app = Petard::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif