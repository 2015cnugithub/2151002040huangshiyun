#ifndef GRAPHICS
#define GRAPHICS
#include <graphics.h>
#endif

class Vehicle{
public:
	virtual void show(int left_top_x, int left_top_y, COLORREF lineColor)=0;
	virtual void hide()=0;
	virtual void move(int move_x, int move_y)=0;
};