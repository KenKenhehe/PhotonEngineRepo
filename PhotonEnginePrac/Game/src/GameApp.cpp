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

int main() {
	Game* game = new Game();
	game->Run();
}