#include "king_piece.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

std::vector<move> king::get_valid_moves(coordinate *from) const {
	std::vector<move> out;
	out.resize(8);
	int dx1 = 1, dx2 = -1, dy1 = 1, dy2 = -1;
	std::pair<int, int> current = from->get_crush();
	coordinate *to;

	to = coordinate::from_crush(current.first + dx1, current.second + dy1);
	out[0] = (move(from, to, move::mtype::VALID));

	to = coordinate::from_crush(current.first + dx2, current.second + dy1);
	out[1] = (move(from, to, move::mtype::VALID));
	
	to = coordinate::from_crush(current.first + 2 * dx1, current.second + 2 * dy1);
	out[2] = (move(from, to, move::mtype::VALID_ATTACK));

	to = coordinate::from_crush(current.first + 2 * dx2, current.second + 2 * dy1);
	out[3] = (move(from, to, move::mtype::VALID_ATTACK));

	to = coordinate::from_crush(current.first + dx1, current.second + dy2);
	out[4] = (move(from, to, move::mtype::VALID));

	to = coordinate::from_crush(current.first + dx2, current.second + dy2);
	out[5] = (move(from, to, move::mtype::VALID));
	
	to = coordinate::from_crush(current.first + 2 * dx1, current.second + 2 * dy2);
	out[6] = (move(from, to, move::mtype::VALID_ATTACK));

	to = coordinate::from_crush(current.first + 2 * dx2, current.second + 2 * dy2);
	out[7] = (move(from, to, move::mtype::VALID_ATTACK));

	return out;
}

/*move::mtype king::is_valid(coordinate from, coordinate to) const {
	return move::mtype::INVALID;
}*/
