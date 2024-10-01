#include "../TessarionEngine/window_manager.hpp"

class Game {
public:
	void init();
	void update();
	void draw();

	// Run the game.
	void run();

private:
	// Window manager.
	TS::WindowManager wm;
};
