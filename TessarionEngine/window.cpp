#include "window.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

using namespace TS;

// Constructor.
Window::Window() {
	window = nullptr;
}

// Deconstructor.
Window::~Window() {
	if(window) {
		delete window;
	}
}

// Initialize the SFML window.
void Window::init(std::string window_name, int screen_width, int screen_height) {
	window = new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), window_name);
}

bool Window::isOpen() {
	return window && window->isOpen();
}

sf::Window* Window::get_window() {
	return window;
}

void Window::close() {
	window->close();
}

void Window::clear() {
	window->clear();
}

void Window::display() {
	window->display();
}
