#include "vector.h"

enum Groups{
	Players,
	Bullets,
	Map
}

typedef struct Object{
	typedef struct{
		int x, y;
	}position;
	Groups group;
	Vector2 direction;
};


/*void move_and_slide(){
	for(array){
		object.position.x += object.direction.x;
		object.position.y += object.direction.y;
	}
}

void*/ 
