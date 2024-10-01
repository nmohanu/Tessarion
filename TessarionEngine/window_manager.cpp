#include "window_manager.hpp"

#include <SFML/Graphics.hpp>

using namespace TS;

WindowManager::WindowManager() {
	window = nullptr;
}

WindowManager::~WindowManager() {
	if(window) {
		delete window;
	}
}

void WindowManager::init(std::string game_title, int screen_width, int screen_height) {
	// Initialize window.
	window = new Window();
	window->init(game_title, screen_width, screen_height);

	return;
}

bool WindowManager::window_running() {
	return window->isOpen();
}

Window* WindowManager::get_window() {
	return window;
}

void WindowManager::close_window() {
	window->close();
}

void WindowManager::clear_window() {
	window->clear();
}
