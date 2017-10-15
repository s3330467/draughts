#include "king_piece.h"

//using namespace of this class
using namespace draughts::model;
using namespace piece; 

std::vector<move> king::get_valid_moves(coordinate from) const {//TODO
	std::vector<move> out;
	out.push_back(move(from, from, move::INVALID));
	return out;
}

move::mtype king::is_valid(coordinate from, coordinate to) const {//TODO
	return move::mtype::INVALID;
}
