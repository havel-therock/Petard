#pragma once

#include "Application.h"

#ifdef PD_PLATFORM_WINDOWS

extern Petard::Application* Petard::CreateApplication();

int main(int argc, char** argv) {

	auto app = Petard::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif