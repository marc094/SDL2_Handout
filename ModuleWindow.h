#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

class SDL_Window;
class SDL_Surface;
// TODO 1: Create the declaration of ModuleWindow class

class ModuleWindow : public Module {
private:
	SDL_Window* _window;
public:
	SDL_Surface* _surface;
public:
	bool Init();
	/*update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();*/
	bool CleanUp();
};

#endif // __ModuleWindow_H__