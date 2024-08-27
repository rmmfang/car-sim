#ifndef __TEST_SPRINTF_H__
#define __TEST_SPRINTF_H__

#include <iostream>
#include "../control/base/matrix.h"

class sPrintf {
	public:

		template <typename T>
		void matrixPrint(const Matrix<T>& ss) {	

			for(int i = 0; i < ss.size_r(); i++) {
				for(int j = 0; j < ss.size_c(); j++) {
					cout << ss[i][j] << " ";
				}
				cout << endl;
			}
		}

		template <typename T> void numPrint(const T& nn) {
			cout << nn << " ";
		}

		sPrintf() {};
		~sPrintf() {};
};

#endif
