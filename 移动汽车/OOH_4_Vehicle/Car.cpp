#ifndef CAR
#define CAR
#include "Car.h"
#endif

Car::Car(){
	this->moved = false;
	this->mvintertime = MOVE_INTER_TIME;

	int road_left_top_x = FRAME_OUTER_MARGIN_X;
	int road_left_top_y = VEHICLE_LEFT_BOTTOM_Y;
	int road_right_bottom_x = FRAME_OUTER_MARGIN_X + ROAD_LENTTH;
	int road_right_bottom_y = VEHICLE_LEFT_BOTTOM_Y + ROAD_HIGH;

	int wheel1_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_RADIUS * 3;
	int wheel1_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_RADIUS;

	int wheel2_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_RADIUS * 13;
	int wheel2_y = wheel1_y;

	int body_left_top_x = VEHICLE_LEFT_BOTTOM_X;
	int body_left_top_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 2;
	int body_right_bottom_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER * 8;
	int body_right_bottom_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER;

	int room_left_top_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER * 2;
	int room_left_top_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 3;
	int room_right_bottom_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER * 6;
	int room_right_bottom_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 2;

	int window1_a_x = room_left_top_x;
	int window1_a_y = room_left_top_y;
	int window1_b_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER;
	int window1_b_y = VEHICLE_LEFT_BOTTOM_Y - VEHICLE_WHEEL_DIAMETER * 2;
	int window1_c_x = window1_a_x;
	int window1_c_y = window1_b_y;

	int window2_a_x = room_right_bottom_x;
	int window2_a_y = window1_a_y;
	int window2_b_x = window2_a_x;
	int window2_b_y = window1_b_y;
	int window2_c_x = VEHICLE_LEFT_BOTTOM_X + VEHICLE_WHEEL_DIAMETER * 7;
	int window2_c_y = window2_b_y;

	int i=0;
	this->pFigures[i++] = new Triangle(window1_a_x, window1_a_y, window1_b_x, window1_b_y, window1_c_x, window1_c_y);
	this->pFigures[i++] = new Rectanglee(room_left_top_x, room_left_top_y, room_right_bottom_x, room_right_bottom_y);
	this->pFigures[i++] = new Triangle(window2_a_x, window2_a_y, window2_b_x, window2_b_y, window2_c_x, window2_c_y);
	this->pFigures[i++] = new Rectanglee(body_left_top_x, body_left_top_y, body_right_bottom_x, body_right_bottom_y);
	this->pFigures[i++] = new Circle(wheel1_x, wheel1_y, VEHICLE_WHEEL_RADIUS);
	this->pFigures[i++] = new Circle(wheel2_x, wheel2_y, VEHICLE_WHEEL_RADIUS);

	fillrectangle(road_left_top_x, road_left_top_y, road_right_bottom_x, road_right_bottom_y);
}

void Car::show(){
	int i=0;
	for(; i<CAR_FIGURES_NUM; i++){
		this->pFigures[i]->show();
	}
}

void Car::hide(){
	int i=0;
	for(; i<CAR_FIGURES_NUM; i++){
		this->pFigures[i]->hide();
	}
}

void Car::move(){
	if(this->moved){
		this->hide();
		int i=0;
		for(; i<CAR_FIGURES_NUM; i++){
			this->pFigures[i]->move(MOVE_INTER_X, MOVE_INTER_Y);
		}
		this->show();
		Sleep(this->mvintertime);
	}
}

bool Car::isMoved(){
	return this->moved;
}

void Car::start(){
	this->moved = true;
}

void Car::pause(){
	this->moved = false;
}

void Car::speedup(){
	if(this->moved){
		this->mvintertime = this->mvintertime / 2 ;
	}
}

void Car::speeddown(){
	if(this->moved){
		this->mvintertime = this->mvintertime * 2 ;
	}
}

void Car::stop(){
	this->moved = false;
}