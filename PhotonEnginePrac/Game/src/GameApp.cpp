#include "Photon.h"

class Game : public Photon::Application
{
public:
	Game();
	~Game();

private:

};

Game::Game()
{
}

Game::~Game()
{
}

Photon::Application* Photon::CreateApp() {
	return new Game();
}