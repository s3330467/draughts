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

std::vector<move> game_board::available_moves(int player_id) {
	std::vector<move> available_moves;
	std::vector<move> piece_moves;
	const piece::game_piece *current_piece, *capture_piece;
	coordinate capture_coords;
	bool attackmoveexists = false;
	int capture_dx, capture_dy;


	for(unsigned int i = 0; i < board.size(); i++) {//itterate through board in x direciton

		for(unsigned int j = 0; j < board[i].size(); j++) {//itterate through board in y direction (the column we just added)
			coordinate coord = coordinate::from_crush(i, j);
			current_piece = get_piece(coord);
			piece_moves = current_piece->get_valid_moves();

			//TODO check which player is having their moves checks, right now it checks all the pieces

			for(unsigned int k = 0; k < piece_moves.size(); k++){
				std::pair<int, int> fromcoords = piece_moves.at(k).from.get_uncrush();
				std::pair<int, int> tocoords = piece_moves.at(k).to.get_uncrush();
				int dx = tocoords.first - fromcoords.first;
				int dy = tocoords.second - fromcoords.second;
				if(piece_moves.at(k).type == move::VALID_ATTACK){
					attackmoveexists = true;
					capture_dx = dx/2;
					capture_dy = dy/2;
					capture_coords = coordinate::from_uncrush((fromcoords.first+capture_dx),(fromcoords.second+capture_dy));
					capture_piece = get_piece(capture_coords);

					//check destination is free
					if(get_piece(piece_moves.at(k).to) != nullptr) continue;
					//check capture piece is there
					if(capture_piece == nullptr) continue;
					if(capture_piece->get_is_top() == current_piece->get_is_top()) continue;
					//available_moves.resize( available_moves.size() + piece_moves.size());//valiant effort, but we dont actually know how big it needs to be
					available_moves.push_back(piece_moves.at(k));
				}
				//TODO: the list of available moves would probably good to have as globals, that the model can access.
				if(piece_moves.at(k).type == move::VALID && !attackmoveexists) {
					if(get_piece(piece_moves.at(k).to) != nullptr) continue;
					available_moves.push_back(piece_moves.at(k));
				}
			}
		}
	}
	if(attackmoveexists){
		//TODO remove any non-attack moves that were added prior to the attack being found
	}
	return available_moves;
}
