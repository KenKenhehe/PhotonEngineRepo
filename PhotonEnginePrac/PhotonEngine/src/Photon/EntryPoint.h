#pragma once

#ifdef PH_PLATFORM_WINDOWS
extern Photon::Application* Photon::CreateApp();

int main(int argc, char** argv) {
	Photon::Log::Init();
	PH_CORE_WARN("Engine initialized!");
	PH_INFO("This is from app");

	auto app = Photon::CreateApp();
	app->Run();
	delete app;
}
#endif // PH_PLATFORM_WINDOWS
