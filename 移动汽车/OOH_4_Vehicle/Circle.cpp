#ifndef CIRCLE
#define CIRCLE
#include "Circle.h"
#endif

Circle::Circle(int center_x, int center_y, int radius){
	this->center_x = center_x;
	this->center_y = center_y;
	this->radius = radius;
}

void Circle::show(){
	circle(this->center_x, this->center_y, this->radius);
}

void Circle::hide(){
	clearcircle(this->center_x, this->center_y, this->radius);
}

void Circle::move(int move_x, int move_y){
	this->center_x = this->center_x + move_x;
	this->center_y = this->center_y + move_y;
}