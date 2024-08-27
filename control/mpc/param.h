#ifndef __MPC_PARAM_H__
#define __MPC_PARAM_H__

#include <vector>
#include "../base/matrix.h"

class Param {
	public:
		/* parameters relate to mpc */
		struct mpcParam { 
			float Np;
			float Nc;
			float Nu; //number of control inputs
	        	float Nx;
			float Ny; //number of control states

			mpcParam(): Np(10), Nc(10), Nu(1), Nx(3), Ny(2) {};
			mpcParam(float np, float nc, float nu, float nx, float ny):Np(np),
                                  Nc(nc), Nu(nu), Nx(nx), Ny(ny) {};
			mpcParam(mpcParam& mp): Np(mp.Np),
                                  Nc(mp.Nc), Nu(mp.Nu), Nx(mp.Nx), Ny(mp.Ny) {};
		};

		/* parameters relate to mpc cost*/
		struct weightParam {
			Matrix<float> Q;
			Matrix<float> R;

			weightParam(): Q(11), R(1) {};
	                weightParam(int qs, int rs): Q(qs), R(rs) {};
			weightParam(int qs, vector<float> qn, int rs, vector<float> rn) : Q(qs, qn), R(rs, rn) {};
			weightParam(Matrix<float>& q , Matrix<float>& r): Q(q), R(r) {};
		};

		mpcParam mpcparam;
                weightParam weightparam;

	//	bool is_increment;

		Param() {};
		Param(float np, float nc, float nu, float nx, float ny, int qs, int rs): mpcparam(np, nc, nu, nx, ny), weightparam(qs, rs) {};
		Param(float np, float nc, float nu, float nx, float ny, int qs, vector<float> qn, int rs, vector<float> rn) : mpcparam(np, nc, nu, nx, ny), weightparam(qs, qn, rs, rn) {};
		Param(mpcParam& mp, weightParam& wp) : mpcparam(mp), weightparam(wp) {

	//		if(is_increment){
	//			mpcparam.Nx = mpcparam.Nx + mpcparam.Nu;
	//		}

		};
	//	Param(Param& p): mpcparam(p.Np, p.Nc, p.Nu, p.Nx, p.Ny), weightparam() {};
};

#endif
