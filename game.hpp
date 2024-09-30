#include "./TessarionEngine/scene.hpp"
#include <string>

class Game {
public:
	void init();
	void update();
	void draw();

	// Title for the window.
	std::string game_title;
};
