#pragma once

#ifdef PT_PLATFORM_WINDOWS

extern Photon::Application* Photon::CreateApplication();

int main(int argc, char** argv) {

	printf("Photon ON!");
	auto game = Photon::CreateApplication();
	game->Run();
	delete game;
}
#endif // PT_PLATFORM_WINDOWS
