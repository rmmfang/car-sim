#include <iostream>
#include "tick.h"
#include "flags.h"

using namespace std;
bool FLAG_END = false;

Tick::Tick(float endT) : startTick(0), endTick(endT), curTick(0), step(0.05) {

}


Tick::Tick(float curT, float endT, float startT): curTick(curT), endTick(endT), startTick(startT), step(0.05) {

}

void
Tick::stepTick(){
	if (curTick + step > endTick) {
		FLAG_END = true;
		std::cerr << "warn: tick out of range." << endl;
	}
	else {
		curTick += step;
	}
}



