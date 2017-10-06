#include "game_board.h"

//using namespace of this class
using namespace draughts::model;

game_board::game_board(int x, int y) : x(x), y(y) {
	board = std::vector<std::vector<std::unique_ptr<game_piece>>>(x);

	for(unsigned int i = 0; i < board.size(); i++) {

		board[i] = std::vector<std::unique_ptr<game_piece>>(y);

		for(unsigned int j = 0; j < board[i].size(); j++) {
			coordinate coord = coordinate::from_crush(i, j);

			if(j < static_cast<unsigned int>(y/2 - 1)) {
				//top
				board[i][j] = std::make_unique<game_piece>(
						game_piece(coord, true));

			} else if(j > static_cast<unsigned int>(y/2)) {
				//bottom
				board[i][j] = std::make_unique<game_piece>(
						game_piece(coord, false));

			} else {
				//middle
				board[i][j] = std::unique_ptr<game_piece>(nullptr);
			}

		}
	}
}

game_piece * game_board::get_piece(coordinate coord) {
	std::pair<int, int> cr = coord.get_crush();

	return board[cr.first][cr.second].get();
}
