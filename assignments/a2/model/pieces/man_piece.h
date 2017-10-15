#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class man : public game_piece {

				public:
					man(coordinate coords, bool is_top) : game_piece(coords, is_top) {}

					char visual() const {
						if(is_top) {
							return 'x';
						} else {
							return 'o';
						}
					}

					move::mtype is_valid(coordinate to) const;
					std::vector<move> get_valid_moves() const;
			};
		}
	}
}
