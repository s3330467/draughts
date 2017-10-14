#include "man_piece.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

game_piece::move_type man::is_valid(coordinate from, coordinate to) {
	std::pair<int, int> fcoord = from.get_uncrush();
	std::pair<int, int> tcoord = to.get_uncrush();
	int dx = tcoord.first - fcoord.first;
	int dy = tcoord.second - fcoord.second;

	if(is_top) {
		//down diagonal is valid
		if(dx == 1 && dy == 1) {
			return move_type::VALID;
		} else if(dx == 2 && dy == 2) {
			return move_type::VALID_ATTACK;
		}
	} else {
		//up diagonal is valid
		if(dx == -1 && dy == -1) {
			return move_type::VALID;
		} else if(dx == -2 && dy == -2) {
			return move_type::VALID_ATTACK;
		}
	}

	return move_type::INVALID;
}
