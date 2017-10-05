#include "coordinate.h"

//using namespace of this class
using namespace draughts::model;

std::pair<int, int> coordinate::get_crush() {
	return std::make_pair(x, y);
}

std::pair<int, int> coordinate::get_uncrush() {
	int newx = x * 2;
	if(y%2 == 0) {
		newx++;
	}
	return std::make_pair(newx, y);
}

static bool is_valid(int x, int y) {
	if(y%2 == 0) {
		//x should be odd
		return x%2;
	} else {
		//x should be even
		return !(x%2);
	}
}
