#ifndef __MPC_STATE_REF_H__
#define __MPC_STATE_REF_H__

#include <memory>
#include "../control/base/matrix.h"

using namespace std;

class StateRef {

	public: 

		vector<vector<float>> yref;

		//Matrix<float> pre_yref;
		//void setpreyRefMatrix(int Np);
		void findrefPos();

		float lastpos;
		shared_ptr<float> curX;
		float refpos;

		StateRef() {};
		StateRef(vector<vector<float>>& yr): yref(yr) {};
		StateRef(vector<vector<float>>& yr, shared_ptr<float> X): yref(yr), curX(X) {};

		~StateRef() {};
};


#endif
