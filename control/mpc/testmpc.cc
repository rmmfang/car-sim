#include "param.h"
#include "testmpc.h"
#include "cost_func_Kinematics.h"
#include "../car/car.h"
#include "solver.h"
#include <iostream>
#include <memory>

typedef Param::mpcParam mpcParam;
typedef Param::weightParam wtParam;
typedef Car::carParam carParam;
typedef Car::motionParam mtnParam;

Matrix<int>
testmpc::testMatrix() {
//	Matrix sum =  ad + au;
//	Matrix de = ad - au;
//	Matrix mul = ad * au;
//	matrixPrint(mul);
//	matrixPrint(sum);
//	matrixPrint(de);

	Q.concatenate_eye(R); 
	//Matrix cc =ad.concatenate_c(au);
	//Matrix ce =ad.concatenate_eye(au);


	Matrix<int> s(5,5);
	cout << "cr = " << Q.size_r() << " " << Q.size_c() << ""  << endl;
	matrixPrint(Q);
	//cout << "cc = " << endl;
	//matrixPrint(cc);
	//cout << "ce  = " << endl;
	//matrixPrint(ce);
//	s = ad;

//	matrixPrint(s);

	return Q;
}

void 
testmpc::testcost() {
	mpcParam mparam(5, 2, 2, 3, 3);
	Matrix<float> Q(3,3,50);
	Matrix<float> R(2,2,30);
	wtParam wtparam(Q,R);
	carParam carparam(3, 1.7, 1500);
	shared_ptr<mtnParam> mtnparam = make_shared<mtnParam>(1,1,3.6,0,0,0,0);

	costFunc* costfcunKinc = new costFuncKinematics(&mparam, &wtparam, carparam, mtnparam, 0.05, true);
	costfcunKinc -> setsystemMatrix();
	costfcunKinc -> setpreMatrix();
	costfcunKinc -> setpreWtMatrix();
	costfcunKinc -> setHMatrix(1000);

	matrixPrint(costfcunKinc -> A);
	matrixPrint(costfcunKinc -> B);
	matrixPrint(costfcunKinc -> C);

	cout << costfcunKinc -> C.size_r() << " " << costfcunKinc -> C.size_c() << endl;

	cout << "preA = " << endl;
	matrixPrint(costfcunKinc -> PreA);
	cout << "preB = " << endl;
	matrixPrint(costfcunKinc -> PreB);
}


void 
testmpc::testsolver() {

	Matrix<float> H(2,2,4);
	Matrix<float> Q(2,1,2);
//	Solver sol(H,Q);

	H.mtx[0][1] = 2.5;
	H.mtx[1][0] = 2.5;

	cout << "H is:" << endl;
	matrixPrint(H);
	Solver sol(H,Q);

	sol.InteriorPointsolver();

	Matrix<float> H1 = H.inverse();

	cout << "H1 reverse is:" << endl;
	matrixPrint(H1);

//	matrixPrint(sol.X);
}
