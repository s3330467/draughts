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
	switch(get_piece(from)->is_valid(to)) {
		case piece::game_piece::VALID:
			//TOOD
			break;
		case piece::game_piece::VALID_ATTACK:
			//TOOD
			break;
		case piece::game_piece::INVALID:
			//TOOD
			break;
	}
	return EOF;
}

std::vector<std::pair<coordinate,coordinate>> game_board::available_moves(int player_id) {
	std::vector<move> available_moves;
	std::vector<move> piece_moves;
	game_piece current_piece, capture_piece;
	coordinate capturecoords;
	bool attackmoveexists = false;
	for(unsigned int i = 0; i < board.size(); i++) {//itterate through board in x direciton

		for(unsigned int j = 0; j < board[i].size(); j++) {//itterate through board in y direction (the column we just added)
			coordinate coord = coordinate::from_crush(i, j);
			current_piece = get_piece(coord);
			piece_moves = current_piece.get_valid_moves();

			//TODO check which player is having their moves checks, right now it checks all the pieces

			for(unsigned int k = 0; k < piece_moves.size(); k++){
				std::pair<int, int> fromcoords = piece_moves.get(k).get_from().get_uncrush();
				std::pair<int, int> tocoords = piece_moves.get(k).get_to().get_uncrush();
				int dx = tocoords.first - fromcoords.first;
				int dy = tocoords.second - fromcoords.second;
				if(piece_moves.get(k).get_move_type()=="attack"){
					attackmoveexists = true;
					capturedx = dx/2
					capturedy = dy/2
					capturecoords = coordinate.from_uncrush((fromcoords.first-capturedx),(fromcoords.second-capturedy));
					capture_piece = get_piece(capturecoords);
					if(get_piece(piece_moves.get(k).get_to()) != nullptr) continue;
					if(capture_piece = nullptr) continue;
					if(capture_piece.get_is_top() == current_piece.get_is_top()) continue;
					//available_moves.reserve( available_moves.size() + piece_moves.size());
					available_moves.push_back(piece_moves.get(k));
				}
				if(piece_moves.get(k).get_move_type()=="move" && attackmoveexists = false){
					if(get_piece(piece_moves.get(k).get_to()) != nullptr) continue;
					available_moves.push_back(piece_moves.get(k));
				}
			}
		}
	}
	if(attackmoveexists = false){
		//TODO remove any non-attack moves that were added prior to the attack being found
	}
	return available_moves;
}
