#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class king : public game_piece {

				public:
					king(bool is_top) : game_piece(is_top) {}

					char visual() const {
						if(is_top) {
							return 'X';
						} else {
							return 'O';
						}
					}

					//move::mtype is_valid(coordinate *from, coordinate *to) const;
					std::vector<move> get_valid_moves(coordinate *from) const;
			};
		}
	}
}
