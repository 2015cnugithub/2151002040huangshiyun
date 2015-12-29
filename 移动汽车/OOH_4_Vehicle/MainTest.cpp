#ifndef GRAPHICS
#define GRAPHICS
#include <graphics.h>
#endif

#ifndef CONIO
#define CONIO
#include <conio.h>
#endif

#ifndef VEHICLE
#define VEHICLE
#include "Vehicle.h"
#endif

#ifndef CAR
#define CAR
#include "Car.h"
#endif

#ifndef TRUCK
#define TRUCK
#include "Truck.h"
#endif

#ifndef LOCATION
#define LOCATION
#include "Location.h"
#endif

int main(){

	initgraph(GRAPH_LENGTH, GRAPH_HIGH);

	char trip1[] = "1.Car 2.Truch 3.Exit";
	outtextxy(TRIP1_X, TRIP1_Y, trip1);

	line(LEFT_TOP_X, LEFT_TOP_Y, RIGHT_TOP_X, RIGHT_TOP_Y);
	line(LEFT_TOP_X, LEFT_TOP_Y, LEFT_BOTTOM_X, LEFT_BOTTOM_Y);
	line(RIGHT_TOP_X, RIGHT_TOP_Y, RIGHT_BOTTOM_X, RIGHT_BOTTOM_Y);
	line(LEFT_BOTTOM_X, RIGHT_BOTTOM_Y, RIGHT_BOTTOM_X, RIGHT_BOTTOM_Y);

	char trip2_1[] = "Press <S> key to start moving";
	char trip2_2[] = "Press <P> key to pause/continue moving";
	char trip2_3[] = "Press <E> key to end moving";
	char trip2_4[] = "Press <+> key to speed up";
	char trip2_5[] = "Press <-> key to speed down";
	outtextxy(TRIP2_X, TRIP2_Y, trip2_1);
	outtextxy(TRIP2_X, TRIP2_Y + TRIP2_INTER_MARGIN_Y, trip2_2);
	outtextxy(TRIP2_X, TRIP2_Y + TRIP2_INTER_MARGIN_Y*2, trip2_3);
	outtextxy(TRIP2_X, TRIP2_Y + TRIP2_INTER_MARGIN_Y*3, trip2_4);
	outtextxy(TRIP2_X, TRIP2_Y + TRIP2_INTER_MARGIN_Y*4, trip2_5);

	Vehicle *pVehicle = new Car();
	pVehicle->show();

	bool end = false;
	while(!end){
		char input = getch();
		if(input=='1'){
			pVehicle->hide();
			pVehicle = new Car();
			pVehicle->show();
		}else if(input=='2'){
			pVehicle->hide();
			pVehicle = new Truck();
			pVehicle->show();
		}else if(input=='3'){
			end = true;
		}else if(input=='S'){
			pVehicle->start();
			while(true){
				if(pVehicle->isMoved()){
					pVehicle->move();
				}
				if(kbhit()){
					input = getch();
					if(input=='P'){
						if(pVehicle->isMoved()){
							pVehicle->pause();
						}else{
							pVehicle->start();
						}
					}else if(input=='+'){
						pVehicle->speedup();
					}else if(input=='-'){
						pVehicle->speeddown();
					}else if(input=='E'){
						pVehicle->stop();
						break;
					}else if(input=='3'){
						end = true;
						break;
					}
				}
			}
		}
	}

	closegraph();

	return 0;
}