#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL\include\SDL.h"

// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

bool ModuleWindow::Init() {
	bool ret_val = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOG("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret_val = false;
	}
	else {
		_window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE);
		if (_window == NULL) {
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret_val = false;
		}
		else {
			_surface = SDL_GetWindowSurface(_window);
			if (_surface == NULL) {
				LOG("Could not get window surface! SDL_Error: %s\n", SDL_GetError());
			}
		}
	}
	return ret_val;
}