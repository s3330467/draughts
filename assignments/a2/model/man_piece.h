#include "coordinate.h"
#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {

		class man_piece : public game_piece {

			public:
			man_piece(coordinate coords, bool is_top) : game_piece(coords, is_top) {}
		};
	}
}
