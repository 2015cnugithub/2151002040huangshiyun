#ifndef FIGURE
#define FIGURE
#include "Figure.h"
#endif

#ifndef LOCATION
#define LOCATION
#include "Location.h"
#endif

#ifndef CIRCLE
#define CIRCLE
#include "Circle.h"
#endif

#ifndef RECTANGLE
#define RECTANGLE
#include "Rectangle.h"
#endif

#ifndef TRIANGLE
#define TRIANGLE
#include "Triangle.h"
#endif

class Vehicle{
public:
	virtual void show() = 0;
	virtual void hide() = 0;
	virtual void move() = 0;
	virtual bool isMoved() = 0;
	virtual void start() = 0;
	virtual void pause() = 0;
	virtual void speedup() = 0;
	virtual void speeddown() = 0;
	virtual void stop() =0;
};