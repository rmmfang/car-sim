#include "car_test.h"
#include <fstream>
#include "../car/flags.h"

extern bool FLAG_END;

carTest::carTest(shared_ptr<Car::motionParam> mparam, Car::carParam &cparam) : car(cparam, mparam) { 
//	Car::motionParam mparam(0.001,0.001,3.6, 0.001, 0, 0, 0);
//	Car::carParam cparam(3, 1.7, 1400);
}
void
carTest::testcar() {
	while(!FLAG_END){
	   // printf("current Tick is %4.2f: flag is %d \n", car.tick.curTick, FLAG_END);
	   car.step();

	   f.open("output.txt");
	   css.ptfile(car.mtparam -> x,car.mtparam -> y,car.mtparam -> phi,f);
	 //  printf("the present state of the car is: %4.2f, %4.2f, %4.2f,\n", car.mtparam.x, car.mtparam.y, car.mtparam.phi);
	}
}
