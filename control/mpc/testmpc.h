#ifndef __MPC_TESTMPC_H__
#define __MPC_TESTMPC_H__

#include "../base/matrix.h"
#include "../../test/sprintf.h"
#include <vector>

using namespace std;

class testmpc : public sPrintf {
	public:
		Matrix<int> Q, R;

		Matrix<int> testMatrix();

		void testcost();
		void testsolver();

		testmpc(): Q(5), R(5) {};
		testmpc(int qc, int rc): Q(qc), R(rc) {};
	        testmpc(int qc, vector<int>& qn, int rc, vector<int>& rn): Q(qc, qn), R(rc, rn) {};

		~testmpc() {};

};

#endif
