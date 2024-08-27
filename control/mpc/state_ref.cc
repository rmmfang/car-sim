#include "state_ref.h"

void 
StateRef::findrefPos() {

	/* mid */

	int end = lastpos + 400 > yref.size() ? yref.size() : lastpos + 400;
	int l = 0, r = end, mid;
	for(int i = lastpos; i < end; i++) {
		
		mid = (l + r) / 2;

		if(yref[mid][0] > *curX) {
			r = mid;
		}
		else if(yref[mid][0] < *curX) {
			l = mid + 1;
		}
		else {
			refpos = mid;
			lastpos = refpos;
			break;
		}
	}
}
