#include "SDL2/SDL.h"

struct Sprite2{
	Sprite(SDL_Renderer *render)
	
	SDL_Texture *texture;
	int width;
	int height;
	int nframes;
};

struct Animation2 : public Sprite2{
	
}
