#ifndef FIGURE
#define FIGURE
#include "Figure.h"
#endif

class Triangle: public Figure{
private:
	int a_x;
	int a_y;
	int b_x;
	int b_y;
	int c_x;
	int c_y;
public:
	Triangle(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y);
	void show();
	void hide();
	void move(int move_x, int move_y);
};