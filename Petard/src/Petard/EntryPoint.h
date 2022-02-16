#pragma once

#include "Application.h"


extern Petard::Application* Petard::CreateApplication();

int main(int argc, char** argv) {
	// not here later
	Petard::Log::Init();
	PD_CORE_INFO("Initialized");

	auto app = Petard::CreateApplication();
	app->Run();
	delete app;
	return 0;
}