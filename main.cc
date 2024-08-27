#include <iostream>
#include <vector>
#include "./test/car_test.h"
#include "./control/mpc/testmpc.h"
#include "./test/mpc.h"

using namespace std;

int main(){
//	Car::carParam cparam(3, 1.7, 1400);
//	Car::motionParam mparam(0.001, 0.001, 3.6, 0.001, 0, 0, 0);
//	carTest car1(mparam, cparam);
//	car1.testcar();

//	int n = 5;
//	vector<int> data(5, 5);
//	vector<int> data2(5, 2);
//	testmpc mpc1(n, data, 5, data2);
       // mpc1.testMatrix();
       //mpc1.testsolver();
       mpc mpctest;
       mpctest.startMPC();       
	return 0;
}
