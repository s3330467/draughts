#include "game_board.h"

//using namespace of this class
using namespace draughts;
using namespace model;

game_board::game_board(int x, int y) : x(x), y(y) {
	board = std::vector<std::vector<std::unique_ptr<piece::game_piece>>>(x);

	for(unsigned int i = 0; i < board.size(); i++) {//itterate through board in x direciton

		board[i] = std::vector<std::unique_ptr<piece::game_piece>>(y);//add column

		for(unsigned int j = 0; j < board[i].size(); j++) {//itterate through board in y direction (the column we just added)
			coordinate coord = coordinate::from_crush(i, j);

			if(j < static_cast<unsigned int>(y/2 - 1)) {
				//top, player 1
				board[i][j] = std::make_unique<piece::man>(
						piece::man(coord, true));

			} else if(j > static_cast<unsigned int>(y/2)) {
				//bottom, player 2
				board[i][j] = std::make_unique<piece::man>(
						piece::man(coord, false));

			} else {
				//middle, no piece
				board[i][j] = std::unique_ptr<piece::game_piece>(nullptr);
			}

		}
	}
}

const piece::game_piece * game_board::get_piece(coordinate coord) const {
	std::pair<int, int> cr = coord.get_crush();

	return board[cr.first][cr.second].get();
}

int game_board::make_move(coordinate from, coordinate to) {
	const piece::game_piece *curr = get_piece(from);
	if(curr == nullptr) {
		//TODO: make the user try their turn again
		return EOF;
	}

	switch(curr->is_valid(to)) {
		case move::VALID:
			//TODO
			break;
		case move::VALID_ATTACK:
			//TODO
			break;
		case move::INVALID:
			//TODO: make the user try their turn again
			return EOF;
	}
	return EOF;
}
