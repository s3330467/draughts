#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class king : public game_piece {

				public:
					king(coordinate coords, bool is_top) : game_piece(coords, is_top) {}

					move::mtype is_valid(coordinate to) const;
					std::vector<move> get_valid_moves() const;
			};
		}
	}
}
