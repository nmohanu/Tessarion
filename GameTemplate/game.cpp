#include "game.hpp"

// Initialize your game.
void Game::init() {
	wm.init("Game", 1920, 1080);
}

// Update your game logic.
void Game::update() {

}

// Draw your game.
void Game::draw() {

}

// Main wm loop.
void Game::run() {
	while(wm.window_running()) {
		sf::Event event;
		
		// Check if window should be closed.
		while(wm.get_window()->get_window()->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				wm.close_window();
			}
		}
	
		// Update game.
		update();
		
		// Clear window.
		wm.clear_window();

		// Draw game
		draw();
	}
}
