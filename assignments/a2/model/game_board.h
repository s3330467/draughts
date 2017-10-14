#include <vector>
#include <memory>

#include "pieces/man_piece.h"
#include "pieces/game_piece.h"

#pragma once

namespace draughts {
	namespace model {

		class game_board {
			std::vector<std::vector<std::unique_ptr<piece::game_piece>>> board;
			int x;
			int y;


			public:
			game_board(int x, int y);

			int get_x() { return x; }
			int get_y() { return y; }

			piece::game_piece * get_piece(coordinate coord);

			int make_move(coordinate from, coordinate to);
		};
	}
}
