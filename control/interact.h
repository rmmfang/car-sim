#ifndef __INTERACT_H__
#define __INTERACT_H__

#include "../control/mpc/state_ref.h"
#include "../control/mpc/cost_func_Kinematics.h"
#include "../control/mpc/state.h"
#include "../control/base/matrix.h"
#include "../car/car.h"
#include <vector>
#include <memory>


class Interact {
	public:

		shared_ptr<Car::motionParam> state;
		StateRef stateref;

		shared_ptr<costFunc> costkinematics;

		/* update the current car's state each sampe */
	//	void stepState();
		/* set cost func and solve the optimval problem */
		void setCost();
		void mpcSolver();


		void getcurstate();
		void getpreRef();

		/* the list of control input */
		float u;
		float rho;

		float T;

		Matrix<float> curstate;
		Matrix<float> pre_yref;

		Interact() {};
		Interact(shared_ptr<Car::motionParam> s, vector<vector<float>> sr, shared_ptr<costFunc> cfk);

		~Interact() {};
};

#endif
