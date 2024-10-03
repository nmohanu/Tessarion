#include "editor.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
	// Initialize SDL.	
  	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    	fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    	return 1;
	}

	// Create SDL window.
	SDL_Window* window = SDL_CreateWindow(
					"hello_sdl2",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN
					);

	if (window == NULL) {
		SDL_Quit();
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Renderer* renderer_ptr = SDL_CreateRenderer(window, -1, 0);

	if(!renderer_ptr) {
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	// Init imgui.
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer_ptr);
	ImGui_ImplSDLRenderer2_Init(renderer_ptr);

	bool running = true;

	// Main loop.
	while(running) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				running = false;
			}
		}

		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("test");

		ImGui::Text("Hello world!");

		ImGui::End();

		ImGui::Render();

		SDL_SetRenderDrawColor(renderer_ptr, 120, 180, 255, 255);
		SDL_RenderClear(renderer_ptr);
		
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer_ptr);

		SDL_RenderPresent(renderer_ptr);

	}

	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(renderer_ptr);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
