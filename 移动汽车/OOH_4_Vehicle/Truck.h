#ifndef VEHICLE
#define VEHICLE
#include "Vehicle.h"
#endif

#define TRUCK_FIGURES_NUM 7

class Truck: public Vehicle{
private:
	Figure *pFigures[TRUCK_FIGURES_NUM];
	bool moved;
	long mvintertime;
public:
	Truck();
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