#ifndef FIGURE
#define FIGURE
#include "Figure.h"
#endif

class Circle: public Figure{
private:
	int center_x;
	int center_y;
	int radius;
public:
	Circle(int center_x, int center_y, int radius);
	void show();
	void hide();
	void move(int move_x, int move_y);
};