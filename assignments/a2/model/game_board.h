#include <vector>
#include <memory>
#include <iostream>

#include "pieces/empty.h"
#include "pieces/man_piece.h"
#include "pieces/king_piece.h"
#include "pieces/game_piece.h"
#include "move.h"

#pragma once

namespace draughts {
	namespace model {

		class game_board {
			std::vector<std::vector<std::unique_ptr<piece::game_piece>>> board;
			int x;
			int y;
			int top_score;
			int bottom_score; 

			public:
			game_board(int x, int y);

			int get_x() { return x; }
			int get_y() { return y; }

			int get_top_score() const {
				return top_score;
			}
			int get_bottom_score() const {
				return bottom_score;
			}

void print_coords(coordinate *from, coordinate *to) const;
void print_coords(coordinate *toprint) const;

			const piece::game_piece * get_piece(coordinate *coord) const;
			/**
			 * make the move on the board, remove the captured piece
			 * does't check anything
			 *
			 * @param move the move to make
			 *
			 * @return true if the player still has to make another move
			 */
			bool make_move(move);
			std::vector<move> available_moves(bool) const;
			bool can_take(coordinate *piece) const;
			static coordinate* get_captured(move);

			bool valid(coordinate *coords) const {
				auto pair = coords->get_crush();
				bool xlow = pair.first >= 0;
				bool ylow = pair.second >= 0;
				bool xhigh = pair.first < x;
				bool yhigh = pair.second < y;
				return xlow && ylow && xhigh && yhigh;
			}
		};
	}
}
