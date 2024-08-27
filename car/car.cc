#include <iostream>
#include "car.h"
#include <cmath>


void
Car::step() {
	tick.stepTick();
	carmodel();
}

void 
Car::carmodel() {

	mtparam -> phidot = mtparam -> v / carparam.length * tan(mtparam -> theta);
	mtparam -> x = mtparam -> x + tick.step * mtparam -> v * cos(mtparam -> phi);
	mtparam -> y = mtparam ->y + tick.step * mtparam -> v * sin(mtparam -> phi);
	mtparam -> phi += tick.step * mtparam -> phidot;

//	printf("the present state of the car is: %4.2f, %4.2f, %4.2f,\n", mtparam.x, mtparam.y, mtparam.phi);

}
		
