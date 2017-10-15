#include "coordinate.h"

//using namespace of this class
using namespace draughts;
using namespace model;

std::pair<int, int> coordinate::get_crush() const {
	return std::make_pair(x, y);
}

std::pair<int, int> coordinate::get_uncrush() const {
	int newx = x * 2;
	if(y%2 != 0) {
		newx++;
	}
	//pauls code has x and y swapped and indices starts at 1
	return std::make_pair(x+1, y+1);
	//return std::make_pair(newx+1, y+1);
}

bool coordinate::is_valid(int x, int y) {
	return true;
	/*x -= 1;
	y -= 1;
	if(y%2 == 0) {
		//x should be odd
		return x%2 == 0;
	} else {
		//x should be even
		return x%2 != 0;
	}*/
}

bool coordinate::check_valid() {
	return !is_valid(0,0) && is_valid(0,1) && !is_valid(1,0) && is_valid(1,1);
}
