#ifndef GRAPHICS
#define GRAPHICS
#include <graphics.h>
#endif

class Figure{
public:
	virtual void show(int left_top_x, int left_top_y, COLORREF lineColor);
	virtual void hide();
	virtual void move(int move_x, int move_y);
};