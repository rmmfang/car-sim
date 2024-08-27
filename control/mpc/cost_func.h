#ifndef __MPC_COST_FUNC_H__
#define __MPC_COST_FUNC_H__

#include "param.h"
#include "state.h"
#include "state_ref.h"
#include "../car/car.h"
#include "../test/car_test.h"
#include "../control/base/matrix.h"
#include <memory>

typedef Car::carParam cParam;
typedef Car::motionParam mParam;

class costFunc {
	public:
		friend class testmpc;

		Param costparam;

	 	virtual void setHMatrix(float rho);
		virtual void setgMatrix(Matrix<float>& yref, Matrix<float>& cur_state);
		virtual void setsystemMatrix() {};
		virtual void setpreMatrix();
		virtual void getCost(Matrix<float>&, Matrix<float>&, float) {};
		void setpreWtMatrix();

		Matrix<float> H;
                Matrix<float> g;
                float T; // time step
                

		bool is_increment;

		costFunc() {};
		costFunc(Param::mpcParam* mpcp, Param::weightParam* wp, cParam cp, shared_ptr<mParam> mp, float t, bool inc);
		virtual ~costFunc() {};

	protected:
		

		//State state;

		cParam cparam;
		shared_ptr<mParam> mparam;

		Matrix<float> preQ, preR;
		Matrix<float> PreA, A;
		Matrix<float> PreB, B;
		Matrix<float> C;

};

#endif
