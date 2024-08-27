#ifndef __IMTPATH_H__
#define __IMTPATH_H__

#include <vector>
#include "../test/cprintf.h"

using namespace std;

class imtPath {

	public:
	vector<vector<float>> data;
	cprintf pp;

	void getpath();
	void printpath();

	imtPath() {};
	~imtPath() {};
};

#endif
