#ifndef __SIMULATE_H__
#define __SIMULATE_H__

#include "../car/car.h"
#include <memory>
#include "../control/interact.h"

class Simulate {

	public:

		Car car;
		Interact interact;

		void simulate();

		Simulate() {};
		Simulate(Car::carParam cm, shared_ptr<Car::motionParam> mm, vector<vector<float>> sr, shared_ptr<costFunc> cfk): car(cm, mm), interact(mm, sr, cfk) {};

		~Simulate() {};

};

#endif
