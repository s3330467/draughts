#include "player.h"

//using namespace of this class
using namespace draughts::model; 

std::string player::get_player_name() {
	return player_name;
}

int player::get_total_score() {
	return total_score;
}
