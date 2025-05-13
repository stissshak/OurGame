#include "vector.h"
#include "collider.h"
#include "sprite.h"

typedef enum Groups{
	Players,
	Bullets,
	Map
}Groups;

typedef struct Position2{
	int x, y;
}Position2;

typedef struct Object{
	Position2 position;
	Groups group;
	Vector2 direction;
	Collider2 collider;
	Sprite2 sprite;
}Object;



