#ifndef __PATH_STRAIGHT_DEFPATH_H__
#define __PATH_STRAIGHT_DEFPATH_H__

#include "../path/abstract_defpath.h"
#include <vector>

typedef abstractPath::pos Pos;

class straightPath : public abstractPath {
public:
	straightPath(){};
	straightPath(float sx, float sy, float ex, float ey): abstractPath(sx,sy,ex,ey) {};
	void setpath() override;

	std::vector<Pos*>  refpath;

	~straightPath() {};

private:
	int length;
};

#endif
