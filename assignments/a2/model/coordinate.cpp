#include "coordinate.h"

//using namespace of this class
using namespace draughts::model;

std::pair<int, int> coordinate::get_crush() {
	return std::make_pair(x/2, y);
}

std::pair<int, int> coordinate::get_uncrush() {
	int newx = x * 2;
	if(y%2 == 0) {
		newx++;
	}
	return std::make_pair(newx, y);
}
