#include "../head/base.h"
//#include "graphics.h" // Здесь пропишем всю работу графики

int running = 1;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Surface* screen_surface = NULL;

SDL_Window* window = NULL;

static int StartGraphic();

static void EndGraphic();


void MNS(Object *buf){
	if(!buf) return;
	buf->position.x += buf->direction.x;
	buf->position.y += buf->direction.y;
	MNS(buf->next);
	MNS(buf->head);
}

void MoveAndSlide(){
	Object *buf = MAIN.head;
	if(!buf){
		fprintf(stderr, "NO OBJECTS WAS CREATED");
		return;	
	}
	MNS(buf);
}


int main(){
	running = StartGraphic();
	while(!running){
		//InputCheck(); // Здесь ввод игрока
		//MoveAndSlide(); // Здесь будет происходить движение всех объекток
		//Collision();	// Проверка взаимодействия всех объектов
		//Graphics();	// Отрисовка графики
	}
	SDL_Delay(2000);
	EndGraphic();
	return 0;
}

static int StartGraphic(){
	if(SDL_Init( SDL_INIT_EVERYTHING) != 0) return 0;
	
	window = SDL_CreateWindow("Hello, SDL 2!",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (window == NULL) return 0;
	screen_surface = SDL_GetWindowSurface(window);
	return 1;
}

static void EndGraphic(){
	SDL_DestroyWindow(window);
	SDL_Quit();
}
