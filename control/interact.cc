#include "interact.h"
#include "../control/mpc/solver.h"
#include "../control/mpc/state_ref.h"
#include <vector>
#include <cmath>
#include <iostream>

Interact::Interact(shared_ptr<Car::motionParam> s, vector<vector<float>> sr, shared_ptr<costFunc> cfk):
	state(s),
	curstate(cfk -> costparam.mpcparam.Nx ,1),
	stateref(sr,  make_shared<float>(s->x)),
        pre_yref(cfk -> costparam.mpcparam.Ny * cfk -> costparam.mpcparam.Np, 1),  
        costkinematics(cfk),
        rho(1000) {

//		costkinematics = new costFunc(*cfk);
	}


void 
Interact::getcurstate() {

	/* get cur state for control
	 * part of param of car motion parameters */

	curstate.mtx[0][0] = state -> x;
	curstate.mtx[1][0] = state -> y;
	curstate.mtx[2][0] = state -> phi;
//	cout << "geting current state: " << curstate.mtx[0][0] << " " << curstate.mtx[1][0] << endl;
	if(costkinematics -> is_increment) {
		curstate.mtx[3][0] = state -> theta;
		curstate.mtx[4][0] = state ->v;
	}

}

void 
Interact::getpreRef() {

	for(int i = 0; i < costkinematics -> costparam.mpcparam.Np; i++) {

		int xd = state -> v * cos(state -> phi);
		int xpre = state -> x + xd * costkinematics -> T;
		int xpos = i * costkinematics -> costparam.mpcparam.Ny;

		if(xpre > stateref.yref[3999][0]) {

			pre_yref.mtx[xpos][0] = stateref.yref[3999][0];
			pre_yref.mtx[xpos + 1][0] = stateref.yref[3999][1];
			pre_yref.mtx[xpos + 2][0] = stateref.yref[3999][2];

		}

		else {
			stateref.findrefPos();
		
			pre_yref.mtx[xpos][0] = stateref.yref[stateref.refpos][0];
                        pre_yref.mtx[xpos + 1][0] = stateref.yref[stateref.refpos][1];
			pre_yref.mtx[xpos + 2][0] = stateref.yref[stateref.refpos][2];
		}
	}
}


void
Interact::setCost() {

	costkinematics -> getCost(pre_yref, curstate, rho);
	
}

void 
Interact::mpcSolver() {
	cout << "geting curent state..." << endl;
	getcurstate();
	cout << "get the predicted reference path..." << endl;
	getpreRef();
	cout << "geting the cost function..." << endl;
	setCost();

	cout << "Solving..." << endl;
	Solver mpcsol(costkinematics -> H, costkinematics -> g);
	mpcsol.InteriorPointsolver();
	
	state -> theta = mpcsol.X[0][0];

	cout << "The H is: " << endl;
	for(int i = 0; i < costkinematics -> H.size_r(); i++) {
		for(int j = 0; j < costkinematics -> H.size_c(); j++) {
			cout << costkinematics -> H[i][j] << " ";
		}
		cout << endl;
	}

	cout << "The control input is: " << mpcsol.X[0][0] << endl;
//	cout << "Have solved MPC, geting the control input..." << endl;
}
