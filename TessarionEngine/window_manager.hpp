#include "window.hpp"

#include <SFML/Window/Event.hpp>

#include <string>

namespace TS {

	class WindowManager {
	public:
		WindowManager();
		~WindowManager();
		void init(std::string game_title, int screen_width, int screen_height);

		// Window functions.
		bool window_running();
		Window* get_window();
		void close_window();
		void clear_window();
	private:
		// Window.
		Window* window;
	};

}
