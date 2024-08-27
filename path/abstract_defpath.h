#ifndef __PATH_DEFPATH_H__
#define __PATH_DEFPATH_H__

#include <vector>

class abstractPath {
	public:
	    abstractPath(): startpos(0,0), endpos(0,100) {};
	    abstractPath(float sx, float sy, float ex, float ey): startpos(sx, sy), endpos(ex, ey) {};
	    struct pos {
		    float xref;
		    float yref;

		    pos(): xref(0), yref(0) {};
		    pos(float _x, float _y) :xref(_x), yref(_y) {};
	    };

	    virtual void setpath() = 0;
	    pos startpos, endpos;

            virtual ~abstractPath() {};
};

#endif
