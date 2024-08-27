#include "simulate.h"
#include <iostream>
#include "../car/flags.h"


extern bool FLAG_END;

void
Simulate::simulate() {

	cout << "steping car state..." << endl;

	while(!FLAG_END) {

	        interact.mpcSolver();
	        car.step();

		cout << "Current car state is: ";
		cout << car.mtparam -> x << " " << car.mtparam -> y << " " << car.mtparam -> phi << endl;

	}

	cout << "Have update the car state!" << endl;
}
