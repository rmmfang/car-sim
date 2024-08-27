#ifndef __MPC_SLOVER_H__
#define __MPC_SOLVER_H__

/* This is a mpc optimival solver for MPC */

#include "../control/base/matrix.h"

class Solver {

	/* base mode : min 1/2 * x^T  * H * x + g^T * x
	 *               constrains; equal & unequal           */

	public:

		Matrix<float> H, g;

		Matrix<float> X; //result

		/* equal constrains */
		Matrix<float> Aeq, beq;

		/* unequal constrains */
		Matrix<float> Aueq, bueq;

		void ActiveSetsolver();
		void InteriorPointsolver();

		Solver(Matrix<float>& H, Matrix<float>& g): H(H), g(g), X(g.c, g.r) {};
		Solver(Matrix<float>& H, Matrix<float>& g, Matrix<float>& A_eq, Matrix<float>& b_eq, Matrix<float>& A_ueq, Matrix<float>& b_ueq);

		~Solver() {};
};

#endif


