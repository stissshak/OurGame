#include "vector.h"
#include "collider.h"
#include "sprite.h"

//////////////////////////////////////// 

typedef enum Group{
	Players,
	Bullets,
	Map
}Group;

typedef struct Position2{
	int x, y;
}Position2;

typedef struct Object Object;
struct Object{
	Position2 position;
	Vector2 direction;
	Group group;
	Collider2 collider;
	Sprite2 sprite;
	Object *next, *head, *parent;

};

///////////////////////////////////////

void addChild(Object *, Object*);
Object *initObject();
Object *createObject(Position2, Vector2, Group, Collider2, Sprite2);
void deleteObject(Object *);

//////////////////////////////////////

Object MAIN = {.head = NULL};

void addChild(Object *parent, Object *child){
	if(!child){
		fprintf(stderr, "Child - NULL ptr\n");
		return;
	}
	child->parent = parent;
	if(!parent->head){
		parent->head = child;
		child->next = NULL;
		return;
	}
	Object *buf = parent->head;
	while(buf->next) buf = buf->next;
	buf->next = child;

}

Object *initObject(){
	Object *buf = calloc(1, sizeof(Object));
	addChild(&MAIN, buf);
	return buf;
}

Object *createObject(Position2 p, Vector2 v, Group g, Collider2 c, Sprite2 s){
	Object *buf = malloc(sizeof(Object));
	addChild(&MAIN, buf);
	buf->position = p;
	buf->direction = v;
	buf->group = g;
	buf->collider = c;
	buf->sprite = s;
	buf->next = NULL;
	buf->head = NULL;
	return buf;
}

void deleteObject(Object *delete){
	if(!delete){
		fprintf(stderr, "Delete - NULL ptr\n");
		return;
	}
	if(!delete->parent){
		fprintf(stderr, "Delete->parent - NULL ptr\n");
		return;
	}
	if(delete->parent->head != delete){
		Object *head = delete->parent->head;
		while(head->next != delete) head = head->next;
		head->next = delete->next;
		free(delete);
		return;
	}
	delete->parent->head = delete->next;
	free(delete);
}

void setPosition(Object *o, int x, int y){
	o->position.x = x;
	o->position.y = y;
}

void setDirection(Object *o, int x, int y){
	o->direction.x = x;
	o->direction.y = y;
}

void setGroup(Object *o, Group g){
	o->group = g;
}

void setCollider(Object *o, int h, int w){
	o->collider.hight = h;
	o->collider.width = w;
}

void setSprite(Object *o){
}
