#include "game_piece.h"

//using namespace of this class
using namespace draughts::model; 

coordinate game_piece::get_coords(){
	return coords;
}

bool game_piece::get_is_top() {
	return is_top;
}

