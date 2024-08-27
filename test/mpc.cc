#include "mpc.h"
#include "../control/mpc/param.h"
#include "../control/mpc/cost_func_Kinematics.h"
#include "../car/car.h"
#include "../control/mpc/solver.h"
#include "../simulate/simulate.h"
#include <iostream>
#include <vector>
#include <memory>
#include "../path/imtpath.h"

typedef Param::mpcParam mpcParam;
typedef Param::weightParam wtParam;
typedef Car::carParam carParam;
typedef Car::motionParam mtnParam;

void
mpc::startMPC() {

	mpcParam mparam(5, 2, 2, 3, 3);
        Matrix<float> Q(3,3,50);
        Matrix<float> R(2,2,30);
        wtParam wtparam(Q,R);
        carParam carparam(3, 1.7, 1500);
        shared_ptr<mtnParam> mtnparam = make_shared<mtnParam>(1,1,3.6,0,0,0,0);

	shared_ptr<costFunc> costfcunKinc(new costFuncKinematics(&mparam, &wtparam, carparam, mtnparam, 0.05, true));

	cout << "Start simulation..." << endl;
	//vector<vector<float>> yref(1000, vector<float>(3));
	//set path
	imtPath path;
	path.getpath();
	cout << "the ref path size:" << path.data.size() << " "<< path.data[0].size() << endl;
//	path.printpath();

	Simulate simulator(carparam, mtnparam, path.data, costfcunKinc);
	simulator.simulate();

	cout << "end simulation" << endl;
//	delete costfcunKinc;
}
