#ifndef TRUCK
#define TRUCK
#include "Truck.h"
#endif

Truck::Truck(){
	this->moved = false;
	this->mvintertime = MOVE_INTER_TIME;

	int body_left_top_x = VEHICLE_LEFT_BOTTOM_X;
	int body_left_top_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 5;
	int body_right_bottom_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER * 9;
	int body_right_bottom_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER;

	int head_left_top_x = body_right_bottom_x + 2;
	int head_left_top_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 4;
	int head_right_bottom_x = head_left_top_x + VEHICLE_WHEEL_DIAMETER * 2;
	int head_right_bottom_y = body_right_bottom_y;

	int wheel1_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_RADIUS * 3;
	int wheel1_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_RADIUS;

	int wheel2_x = wheel1_x + VEHICLE_WHEEL_RADIUS * 3;
	int wheel2_y = wheel1_y;

	int wheel3_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_RADIUS * 12;
	int wheel3_y = wheel1_y;

	int wheel4_x = wheel3_x + VEHICLE_WHEEL_RADIUS * 3;
	int wheel4_y = wheel1_y;

	int wheel5_x = head_right_bottom_x - VEHICLE_WHEEL_DIAMETER;
	int wheel5_y = wheel1_y;

	int road_left_top_x = FRAME_OUTER_MARGIN_X;
	int road_left_top_y = VEHICLE_LEFT_BOTTOM_Y;
	int road_right_bottom_x = FRAME_OUTER_MARGIN_X + ROAD_LENTTH;
	int road_right_bottom_y = VEHICLE_LEFT_BOTTOM_Y + ROAD_HIGH;

	int i=0;
	this->pFigures[i++] = new Rectanglee(body_left_top_x, body_left_top_y, body_right_bottom_x, body_right_bottom_y);
	this->pFigures[i++] = new Rectanglee(head_left_top_x, head_left_top_y, head_right_bottom_x, head_right_bottom_y);
	this->pFigures[i++] = new Circle(wheel1_x, wheel1_y, VEHICLE_WHEEL_RADIUS);
	this->pFigures[i++] = new Circle(wheel2_x, wheel2_y, VEHICLE_WHEEL_RADIUS);
	this->pFigures[i++] = new Circle(wheel3_x, wheel3_y, VEHICLE_WHEEL_RADIUS);
	this->pFigures[i++] = new Circle(wheel4_x, wheel4_y, VEHICLE_WHEEL_RADIUS);
	this->pFigures[i++] = new Circle(wheel5_x, wheel5_y, VEHICLE_WHEEL_RADIUS);

	fillrectangle(road_left_top_x, road_left_top_y, road_right_bottom_x, road_right_bottom_y);
}

void Truck::show(){
	int i=0;
	for(; i<TRUCK_FIGURES_NUM; i++){
		this->pFigures[i]->show();
	}
}

void Truck::hide(){
	int i=0;
	for(; i<TRUCK_FIGURES_NUM; i++){
		this->pFigures[i]->hide();
	}
}

void Truck::move(){
	if(this->moved){
		this->hide();
		int i=0;
		for(; i<TRUCK_FIGURES_NUM; i++){
			this->pFigures[i]->move(MOVE_INTER_X, MOVE_INTER_Y);
		}
		this->show();
		Sleep(this->mvintertime);
	}
}

bool Truck::isMoved(){
	return this->moved;
}

void Truck::start(){
	this->moved = true;
}

void Truck::pause(){
	this->moved = false;
}

void Truck::speedup(){
	if(this->moved){
		this->mvintertime = this->mvintertime / 2 ;
	}
}

void Truck::speeddown(){
	if(this->moved){
		this->mvintertime = this->mvintertime * 2 ;
	}
}

void Truck::stop(){
	this->moved = false;
}
