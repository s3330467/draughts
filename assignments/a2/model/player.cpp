#include "player.h"

//using namespace of this class
using namespace draughts;
using namespace model; 

std::string player::get_player_name() const {
	return player_name;
}

int player::get_total_score() const {
	return total_score;
}

int player::get_id() const {
	return id;
}

