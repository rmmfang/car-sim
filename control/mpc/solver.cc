#include "solver.h"
#include <iostream>

Solver::Solver(Matrix<float>& H, Matrix<float>& g, Matrix<float>& A_eq, Matrix<float>& b_eq, Matrix<float>& A_ueq, Matrix<float>& b_ueq):
	H(H), g(g),
	Aeq(A_eq),
	beq(b_eq),
	Aueq(A_ueq),
	bueq(b_ueq),
        X(g.size_r(),g.size_c()) {
	}

void 
Solver::InteriorPointsolver() {

	//cout <<"Solving MPC..." << endl;

	Matrix<float> H1 = H.inverse();
	Matrix<float> g1 = g.transpose();
        
//cout << "H1 size:" << H1.size_r() << " " << H1.size_c() << endl;
//cout << "rg size" <<g1.size_r() << " " << g1.size_c() << endl;
//cout << "rg size" <<X.size_r() << " " << X.size_c() << endl;

	X = H1 * g1;
	//cout << "MPC Solve done!" << endl;

}

