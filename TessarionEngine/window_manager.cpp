#include "window_manager.hpp"

#include <SFML/Graphics.hpp>

TS::WindowManager::WindowManager() {
	window = nullptr;
}

TS::WindowManager::~WindowManager() {
	if(window) {
		delete window;
	}
}

void TS::WindowManager::init(std::string game_title, int screen_width, int screen_height) {
	// Initialize window.
	window = new Window();
	window->init(game_title, screen_width, screen_height);

	return;
}

bool TS::WindowManager::window_running() {
	return window->isOpen();
}

Window* TS::WindowManager::get_window() {
	return window;
}

void TS::WindowManager::close_window() {
	window->close();
}

void TS::WindowManager::clear_window() {
	window->clear();
}
