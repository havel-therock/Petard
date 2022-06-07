#pragma once

#include "Application.h"

extern Petard::Application* Petard::CreateApplication();

int main(int argc, char** argv) {
	// not here later
	Petard::Log::Init();
	PD_CORE_INFO("Initializing");
	// INFO about drivers gpus used...

	auto app = Petard::CreateApplication();
	PD_CORE_INFO("Engine start...");
	app->Run();
	delete app;
	return 0;
}