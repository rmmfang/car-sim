#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <memory>
#include "tick.h"

using namespace std;

class Car {
	public:
		friend class carTest;
               
		virtual void carmodel();
		void step();

		struct carParam {
			float length;
		        float width;
			float weight;

			carParam(): length(3), width(1.5), weight(1000) {};
			carParam(carParam &p): length(p.length), width(p.width), weight(p.weight) {};
			carParam(float l, float wh, float wt): length(l), width(wh), weight(wt) {};
		};

		struct motionParam {
			float x, y;
                        float v;
                        float phi, theta;
			float phidot;
			float a;

                        motionParam(): x(0), y(0), v(0), phi(0), phidot(0), a(0), theta(0) {};
			motionParam(motionParam &p): x(p.x), y(p.y), v(p.v), phi(p.phi), phidot(p.phidot), a(p.a), theta(p.theta) {};
                        motionParam(float _x, float _y, float _v, float _phi,float _phidot, float _a, float _theta): x(_x), y(_y), v(_v), phi(_phi), phidot(_phidot), a(_a), theta(_theta) {};
                };

		Car(): tick(10) {};
		// Car(carParam &carp, motionParam &motionp): carparam(carp), mtparam(motionp), tick(10) {};
		Car(carParam &carp, shared_ptr<motionParam> motionp): carparam(carp), mtparam(motionp), tick(20) {};

		virtual ~Car() {};

		carParam carparam;
		Tick tick;
		shared_ptr<motionParam> mtparam;
};

#endif
