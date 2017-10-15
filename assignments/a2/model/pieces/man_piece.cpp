#include "man_piece.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece;

std::vector<move> man::get_valid_moves() const {
	std::vector<move> out;
	out.resize(4);
	int dx1 = 1, dx2 = -1, dy = 1;
	std::pair<int, int> current = coords.get_crush();

	if(!is_top) {
		dy = -1;
	}

	coordinate to = coordinate::from_crush(current.first + dx1, current.second + dy);
	out[0] = (move(coords, to, move::mtype::VALID));

	to = coordinate::from_crush(current.first + dx2, current.second + dy);
	out[1] = (move(coords, to, move::mtype::VALID));
	
	to = coordinate::from_crush(current.first + 2 * dx1, current.second + 2 * dy);
	out[2] = (move(coords, to, move::mtype::VALID_ATTACK));

	to = coordinate::from_crush(current.first + 2 * dx2, current.second + 2 * dy);
	out[3] = (move(coords, to, move::mtype::VALID_ATTACK));

	return out;
}

move::mtype man::is_valid(coordinate to) const {
	std::pair<int, int> curpos = coords.get_uncrush();
	std::pair<int, int> newpos = to.get_uncrush();
	int dx = newpos.first - curpos.first;
	int dy = newpos.second - curpos.second;

	if(is_top) {
		//down diagonal is valid
		if((dx == 1 || dx == -1) && dy == 1) {
			return move::mtype::VALID;
		} else if((dx == 2 || dx == -2) && dy == 2) {
			return move::mtype::VALID_ATTACK;
		}
	} else {
		//up diagonal is valid
		if((dx == 1 || dx == -1) && dy == -1) {
			return move::mtype::VALID;
		} else if((dx == 2 || dx == -2) && dy == -2) {
			return move::mtype::VALID_ATTACK;
		}
	}

	return move::mtype::INVALID;
}
