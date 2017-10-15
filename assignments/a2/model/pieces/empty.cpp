#include "empty.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

std::vector<move> empty::get_valid_moves() const {
	std::vector<move> out;
	out.push_back(move(coords, coords, move::INVALID));
	return out;
}

move::mtype empty::is_valid(coordinate to) const {
	return move::mtype::INVALID;
}
