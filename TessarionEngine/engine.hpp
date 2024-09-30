#include "window.hpp"
#include "../game.hpp"

#include <string>

class Engine {
public:
	Engine();
	~Engine();
	void init(Game& game);
	void run();
private:
	// Window properties.
	std::string game_name;
	int screen_width;
	int screen_height;
	
	// Window.
	Window* window;

	// Game to run.
	Game* game;
};
