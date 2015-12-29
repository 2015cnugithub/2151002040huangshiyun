#ifndef TRIANGLE
#define TRIANGLE
#include "Triangle.h"
#endif

Triangle::Triangle(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y){
	this->a_x = a_x;
	this->a_y = a_y;
	this->b_x = b_x;
	this->b_y = b_y;
	this->c_x = c_x;
	this->c_y = c_y;
}

void Triangle::show(){
	POINT pts[] = {{this->a_x, this->a_y}, {this->b_x, this->b_y}, {this->c_x, this->c_y}};
	polygon(pts, 3);
}

void Triangle::hide(){
	POINT pts[] = {{this->a_x, this->a_y}, {this->b_x, this->b_y}, {this->c_x, this->c_y}};
	clearpolygon(pts, 3);
}

void Triangle::move(int move_x, int move_y){
	this->a_x = this->a_x + move_x;
	this->a_y = this->a_y + move_y;
	this->b_x = this->b_x + move_x;
	this->b_y = this->b_y + move_y;
	this->c_x = this->c_x + move_x;
	this->c_y = this->c_y + move_y;
}