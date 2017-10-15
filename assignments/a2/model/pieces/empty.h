#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class empty : public game_piece {

				public:
					empty(bool is_top) : game_piece(is_top) {}

					char visual() const {
						return ' ';
					}

					move::mtype is_valid(coordinate from, coordinate to) const;
					std::vector<move> get_valid_moves(coordinate from) const;
			};
		}
	}
}
