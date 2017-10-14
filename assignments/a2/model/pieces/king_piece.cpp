#include "king_piece.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

std::vector<move> king::get_valid_moves() const {//TODO
	std::vector<move> out;
	out.push_back(move(coords, coords, move::INVALID));
	return out;
}

move::move_type king::is_valid(coordinate to) const {//TODO
	return move::move_type::INVALID;
}
