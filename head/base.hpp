#include "vector.hpp"
#include "collider.hpp"
#include "sprite.hpp"

enum class Group{
};

struct Position2{
	Position2(double _x = 0, double _y = 0) : x(_x), y(_y);
	double x, y;
};

Object MAIN  = {.head = NULL};

struct Object{
	public:

	friend Object *initObject(){
		Object *buf = new Object;
		addChild(&MAIN, buf);
		return buf;
	}

	friend 

	Position2 position;
	Collider2 collider;
	Group group;

	private:

	void addChild( Object *child){
		if(!child){}
		child->parent = this;;
		if(!head){
			this->head = child;
			child->next = NULL;
			return;
		}
		Object *buf = this->head;
		while(buf->next) buf = buf->next;
		buf->next = child;
	}

	Object *next, *head, *parent;	
};

struct StaticObject : public Object{
	public:
	Sprite2 sprite;
};



