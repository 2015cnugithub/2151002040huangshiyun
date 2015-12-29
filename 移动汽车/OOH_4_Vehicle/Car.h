#ifndef VEHICLE
#define VEHICLE
#include "Vehicle.h"
#endif

#define CAR_FIGURES_NUM 6

class Car: public Vehicle{
private:
	Figure *pFigures[CAR_FIGURES_NUM];
	bool moved;
	long mvintertime;
public:
	Car();
	void show();
	void hide();
	void move();
	bool isMoved();
	void start();
	void pause();
	void speedup();
	void speeddown();
	void stop();
};