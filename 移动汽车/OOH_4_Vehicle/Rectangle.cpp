#ifndef RECTANGLE
#define RECTANGLE
#include "Rectangle.h"
#endif

Rectanglee::Rectanglee(int left_top_x, int left_top_y, int right_bottom_x, int right_bottom_y){
	this->left_top_x = left_top_x;
	this->left_top_y = left_top_y;
	this->right_bottom_x = right_bottom_x;
	this->right_bottom_y = right_bottom_y;
}

void Rectanglee::show(){
	rectangle(this->left_top_x, this->left_top_y, this->right_bottom_x, this->right_bottom_y);
}

void Rectanglee::hide(){
	clearrectangle(this->left_top_x, this->left_top_y, this->right_bottom_x, this->right_bottom_y);
}

void Rectanglee::move(int move_x, int move_y){
	this->left_top_x = this->left_top_x + move_x;
	this->left_top_y = this->left_top_y + move_y;
	this->right_bottom_x = this->right_bottom_x + move_x;
	this->right_bottom_y = this->right_bottom_y + move_y;
}