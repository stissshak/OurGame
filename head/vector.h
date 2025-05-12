#include <math.h>
#include <stdlib.h>


typedef struct Vector2{
	double x, y;
}Vector2;

typedef struct Vector3{
	double x, y, z;
}Vector3;


Vector2 *createVector2(double, double);
Vector2 *multVector2(Vector2*, double);
Vector2 *sumVector2(Vector2*, Vector2*);
Vector2 *difVector2(Vector2*, Vector2*);
double scalarVector2(Vector2*, Vector2*);
double lenVector2(Vector2*);
Vector2 *normilizeVector2(Vector2*);
double angleVector2(Vector2*, Vector2*);
Vector2 *rotateVector2(Vector2*, double);

Vector2 *createVector2(double x, double y){
	Vector2 *a = malloc(sizeof(Vector2));
	a->x = x;
	a->y = y;
	return a;
}

Vector2 *multVector2(Vector2 *a, double num){
	return createVector2(a->x * num, a->y * num);
}

Vector2 *sumVector2(Vector2 *a, Vector2 *b){
	return createVector2(a->x + b->x, a->y + b->y);
}

Vector2 *difVector2(Vector2 *a, Vector2 *b){
	return createVector2(a->x - b->x, a->y - b->y);
}

double scalarVector2(Vector2 *a, Vector2 *b){
	return (a->x*b->x + a->y*b->y);
}

double lenVector2(Vector2 *a){
	return sqrt(scalarVector2(a, a));
}

Vector2 *normilizeVector2(Vector2 *a){
	double lenght = lenVector2(a);
	a->x /= lenght;
        a->y /= lenght;
	return a;	
}

double angleVector2(Vector2 *a, Vector2 *b){
	return acos(fabs(scalarVector2(a, b))/lenVector2(a)*lenVector2(b));
}

Vector2 *rotateVector2(Vector2 *a, double angle){
	a->x = a->x * cos(angle) + a->y * sin(angle);
	a->y = a->y * cos(angle) - a->x * sin(angle);
	return a;
}

Vector2 *reflectVector2(Vector2 *a){
	a->x = -a->x;
	a->y = -a->y;
	return a;
}
