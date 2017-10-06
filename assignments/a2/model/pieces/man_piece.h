#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class man : public game_piece {

				public:
					man(coordinate coords, bool is_top) : game_piece(coords, is_top) {}
			};
		}
	}
}
