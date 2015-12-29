#ifndef FIGURE
#define FIGURE
#include "Figure.h"
#endif

class Rectanglee: public Figure{
private:
	int left_top_x;
	int left_top_y;
	int right_bottom_x;
	int right_bottom_y;
public:
	Rectanglee(int left_top_x, int left_top_y, int right_bottom_x, int right_bottom_y);
	void show();
	void hide();
	void move(int move_x, int move_y);
};