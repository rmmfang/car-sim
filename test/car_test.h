#ifndef __TEST_CAR_TEST_H__
#define __TEST_CAR_TEST_H__

#include "../car/car.h"
#include "cprintf.h"
#include <fstream>
#include <iostream>
#include <memory>

class carTest {
	public:
	    carTest() {};
	    carTest(shared_ptr<Car::motionParam>, Car::carParam&);
	    Car car;
	    void testcar();

	private:
	    cprintf css;
	    std::ofstream f;
};
#endif
