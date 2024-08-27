
#ifndef __CAR_TICK_H__
#define __CAR_TICK_H__

#include <iostream>

using namespace std;

class Tick {
	public:

		friend class carTest;
		Tick() {};
		Tick(float curT, float endT, float startT);
		Tick(float endT);
		
		float getTick() { return curTick; };
		void stepTick();
		void stopTick();

		float step;

		~Tick() {};

         private:
		float curTick;
                float endTick;
                float startTick;

};

#endif
