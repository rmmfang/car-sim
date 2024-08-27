#ifndef __TEST_CPRINTF_H__
#define __TEST_CPRINTF_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
class cprintf {
public:
	cprintf() {};
	//cptintf(string name): fname(name) {};

	// ofstream f;
	stringstream oss;
	//string fname;
	template <typename T> void ptfile(T &arg1, T &arg2, T &arg3, ofstream &f) {

		oss << arg1 << " " << arg2 << " " << arg3 << "\n";
		if(!f) {
			cout <<"can't able to build file!" << endl;
		}
		f << oss.str();
		f.close();
		
	}

	~cprintf() {};
};

#endif
