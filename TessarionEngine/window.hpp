#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Window {
public:
	Window();
	~Window();
	void init(std::string window_name, int screen_width, int screen_height);
	bool isOpen();
	void close();
	void clear();
	void display();
	sf::Window* get_window();
private:
	sf::RenderWindow* window;
};
