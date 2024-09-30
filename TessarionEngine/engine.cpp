#include "engine.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

Engine::Engine() {
	window = nullptr;
}

Engine::~Engine() {
	if(window) {
		delete window;
	}
}

void Engine::init(Game& game) {
	this->game = &game;
	this->game_name = game.game_title;

	// Init game.
	game.init();

	// Initialize window.
	window = new Window();
	window->init(game_name, screen_width, screen_height);

	return;
}

// Main engine loop.
void Engine::run() {
	while(window->isOpen()) {
		sf::Event event;
		
		// Check if window should be closed.
		while(window->get_window()->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window->close();
			}
		}
		
		// Clear window.
		window->clear();

		// Draw game.
		game->draw();
	}
}
