#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class king : public game_piece {

				public:
					king(coordinate coords, bool is_top) : game_piece(coords, is_top) {}
			};
		}
	}
}
