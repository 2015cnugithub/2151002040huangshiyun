#ifndef GRAPHICS
#define GRAPHICS
#include <graphics.h>
#endif

#ifndef CONIO
#define CONIO
#include <conio.h>
#endif

class Figure{
public:
	virtual void show() = 0;
	virtual void hide() = 0;
	virtual void move(int move_x, int move_y) = 0;
};