#ifndef __MPC_STATE_H__
#define __MPC_STATE_H__

#include "param.h"

class State {
	public:
		struct X {
			float x;
			float y;
			float phi;

			X() {};
			X(float _x, float _y, float _phi): x(_x), y(_y), phi(_phi) {};
		};

//		struct u {
//			float delta;

//			u() {};
//			u(float _d): delta(_d) {};
//		};

		State() {};
		//State(float _x, float _y, float _phi, float _u): X(_x, _y, _phi), u(_u) {};

		~State() {};
};

#endif
