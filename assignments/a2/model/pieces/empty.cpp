#include "empty.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

std::vector<move> empty::get_valid_moves(coordinate from) const {
	std::vector<move> out;
	out.push_back(move(from, from, move::INVALID));
	return out;
}

move::mtype empty::is_valid(coordinate from, coordinate to) const {
	return move::mtype::INVALID;
}
