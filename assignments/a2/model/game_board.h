#include <vector>
#include <memory>

#include "game_piece.h"

#pragma once

namespace draughts {
	namespace model {

		class game_board {
			std::vector<std::vector<std::unique_ptr<game_piece>>> board;
			int x;
			int y;


			public:
			game_board(int x, int y);

			int get_x() { return x; }
			int get_y() { return y; }

			game_piece * get_piece(coordinate coord);
		};
	}
}
