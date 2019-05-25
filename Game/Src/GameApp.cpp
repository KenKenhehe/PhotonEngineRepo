#include<Photon.h>

class Game : public Photon::Application
{
public:
	Game() {
	
	}
	~Game() {

	}


	
};

Photon::Application* Photon::CreateApplication() {
	return new Game();
}