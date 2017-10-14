#include "game_piece.h"

//using namespace of this class
using namespace draughts;
using namespace model;
using namespace piece; 

coordinate game_piece::get_coords() const {
	return coords;
}

bool game_piece::get_is_top() const {
	return is_top;
}

