#include "cost_func.h"
//#include <cmath>


typedef Car::carParam carParam;
typedef Car::motionParam mtnParam;
typedef Param::mpcParam mpcParam;
typedef Param::weightParam wtParam;


costFunc::costFunc(mpcParam* mpp, wtParam* wp, carParam cp, shared_ptr<mtnParam> mp, float t, bool inc): costparam(*mpp, *wp),
       	cparam(cp), 
	mparam(mp), 
	A(mpp -> Nx),  
        B(mpp -> Nx, mpp -> Nu),
	C(mpp -> Ny, mpp -> Nx, 1),
	PreB(mpp -> Np * mpp -> Ny, mpp -> Nu * mpp ->  Np),
        PreA(mpp -> Ny * mpp -> Np, mpp -> Nx + inc * mpp -> Nu),
	preQ(wp -> Q),
	preR(wp -> R),
	H(mpp -> Nu * mpp -> Nc + 1, mpp -> Nu * mpp -> Nc + 1),
	g(1, mpp -> Nc * mpp -> Nc + 1),
	T(t), 
        is_increment(inc) {

          /* initialize the A, B system matric int the construct 
	   * default: increment  system mode */

		if(is_increment) {

			costparam.mpcparam.Nx = costparam.mpcparam.Nx + costparam.mpcparam.Nu;

		}

//		if(mpp -> Nx != 3 || mpp -> Nu != 2) {
//			throw "Warnning: in the Konematics mode, system matrix size must match";	
//		}

}

void
costFunc::setpreMatrix() {

	int n = costparam.mpcparam.Nx;
	Matrix<float> preA(costparam.mpcparam.Ny, n);
	Matrix<float> preB(costparam.mpcparam.Np * costparam.mpcparam.Ny, costparam.mpcparam.Nu);

	/* construct the pre matrix in cols */
	for(int j = 0; j < costparam.mpcparam.Nc; j++) {

		Matrix<float> preA_col(C.size_r(), B.size_c());

		for(int i = 0; i < costparam.mpcparam.Np; i++) {
			if(i >= j) {

				/* get Am */
				Matrix<float> Am(A.size_r(), A.size_c(), 1);
//				cout << "get Am" << endl;

				for(int k = 0; k < i - j; k++) {
					Am = Am * A;
				}

				/* get a col of preA */
//				cout << "get a col of preA" << endl;

				if(i == 0) {
					preA_col = C * Am * B;
				}
				else {
					Matrix<float> Cm = C * Am * B;
					preA_col.concatenate_r(Cm);
				}
			}
			else {
				Matrix<float> zeroM(C.size_r(), B.size_c());

				if(i == 0) {
					preA_col = zeroM;
				}
				else {
					preA_col.concatenate_r(zeroM);
				}
			}
		}

		/* join each col into preA Matrix<float> */
//		cout << "join each col into preA matrix" << endl;

		if(j == 0) {
			preB = preA_col;
		}
		else {
			preB.concatenate_c(preA_col);
		}
	}


	/* set preA matrix */
//	cout << "set preB matrix" << endl;

	for(int i = 0; i < costparam.mpcparam.Np; i++) {

		Matrix<float> Am(A);

		for(int j = 0; j < i; j++) {
			Am = Am * A;
		}

		Matrix<float> Bp = C * Am;
		
//		cout << "preB = " << preB.size_r() << " " << preB.size_c() << endl;
//		cout << " 11 " << endl;
//		cout << preA.size_r() << " " << preA.size_c() << endl;
//		cout << Bp.size_r() << " " << Bp.size_c() << endl;

		if(i == 0) {
			preA = Bp;
		}
		else {
			preA.concatenate_r(Bp);
		}
	//	cout << preA.size_r() << " " << preA.size_c() << endl;
	}
	cout << preA.size_r() << " " << preA.size_c() << endl;

	PreA = preA;
	PreB = preB;

}

void 
costFunc::setpreWtMatrix() {
	
	for(int i = 0; i < costparam.mpcparam.Np; i++) {

		if(i == 0) {
			preQ = costparam.weightparam.Q;
		}
		else {
			preQ.concatenate_eye(costparam.weightparam.Q);
		}
	}

	for(int i = 0; i < costparam.mpcparam.Nc; i++) {
		
		if(i == 0) {
			preR = costparam.weightparam.R;
		}
		else {
			preR.concatenate_eye(costparam.weightparam.R);
		}
	}
}

void
costFunc::setHMatrix(float rho) {

        Matrix<float> H2(costparam.mpcparam.Nu * costparam.mpcparam.Nc, 1);
        Matrix<float> H3(1, costparam.mpcparam.Nu * costparam.mpcparam.Nc);
	Matrix<float> H4(1);

	//cout << " set H11 Matrix<float> " << endl;
        Matrix<float> preBT = PreB.transpose();
	//cout << preQ.size_r() << " " << preQ.size_c() << endl;
	//cout << preR.size_r() << " " << preR.size_c() << endl;

	Matrix<float> H11 = preBT * preQ * PreB;
	H11 = H11 + H11;
	//cout << H11.size_r() << " " << H11.size_c() << endl;
	Matrix<float> H1 = H11 + preR;
	//cout << " set H4 matrix " << endl;
	H4.mtx[0][0] = rho;

	H1.concatenate_c(H2);
	H3.concatenate_c(H4);
	H1.concatenate_r(H3);

	H = H1;
	
}

void 
costFunc::setgMatrix(Matrix<float>& yref, Matrix<float>& cur_state) {

        //cout << "yref.size is:";
	Matrix<float> E = yref - PreA * cur_state;

	//cout << "get g matrix..." << endl;
	Matrix<float> ET = E.transpose();
	Matrix<float> g1 = ET * preQ * PreB;

	//cout << "get g1" << endl;
	Matrix<float> g2(1);
	g2[0][0] = 0;

	g1.concatenate_c(g2);

	//cout <<"get g1" << g1.size_r() << " " << g1.size_c() << endl;
	//cout <<"get g" << g.size_r() << " " << g.size_c() << endl;
	g = g1;

	//cout << "done" << endl;
}
