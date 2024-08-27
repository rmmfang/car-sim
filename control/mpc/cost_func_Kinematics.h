#ifndef __MPC_COST_FUNC_KINEMATICS_H__
#define __MPC_COST_FUNC_KINEMATICS_H__

#include "cost_func.h"
#include <memory>

class costFuncKinematics: public costFunc {

	public:

	//	bool isincrement;
		void setsystemMatrix() override;
		void getCost(Matrix<float>&, Matrix<float>&, float) override;
	//	void setWtMatrix() override;

		costFuncKinematics() {};
		costFuncKinematics(Param::mpcParam* mpcp, Param::weightParam* wp, cParam cp,shared_ptr<mParam> mp, float t, bool increment);
};


#endif
