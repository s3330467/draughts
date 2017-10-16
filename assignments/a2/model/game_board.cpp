#include "game_board.h"

//using namespace of this class
using namespace draughts;
using namespace model;

game_board::game_board(int x, int y) : x(x), y(y) {
	board = std::vector<std::vector<std::unique_ptr<piece::game_piece>>>(x);

	for(unsigned int i = 0; i < board.size(); i++) {//iterate through board in x direciton

		board[i] = std::vector<std::unique_ptr<piece::game_piece>>(y);//add column

		for(unsigned int j = 0; j < board[i].size(); j++) {//iterate through board in y direction (the column we just added)

			if(j < static_cast<unsigned int>(y/2 - 1) && j%2 == i%2) {
				//top, player 1
				board[i][j] = std::make_unique<piece::man>(
						piece::man(true));

			} else if(j > static_cast<unsigned int>(y/2) && j%2 == i%2) {
				//bottom, player 2
				board[i][j] = std::make_unique<piece::man>(
						piece::man(false));

			} else {
				//middle, no piece
				board[i][j] = std::make_unique<piece::empty>(
						piece::empty(false));
			}

		}
	}
}

const piece::game_piece * game_board::get_piece(coordinate *coord) const {
	std::pair<int, int> cr = coord->get_crush();

	//printf("get_piece x:%d y:%d\n", cr.first, cr.second);
	if(!valid(coord)) return nullptr;
	return board[cr.first][cr.second].get();
}

bool game_board::make_move(move move) {
	std::pair<int, int> from_coord = move.from->get_crush();
	std::pair<int, int> to_coord = move.to->get_crush();
	if(move.type == move::VALID) {
		//non attack
		board[from_coord.first][from_coord.second].swap(board[to_coord.first][to_coord.second]);

		return can_take(move.to);
	} else if(move.type == move::VALID_ATTACK) {
		//attack move
		coordinate *capturedpos = get_captured(move);
		std::pair<int, int> captured_coord = capturedpos->get_crush();
		board[captured_coord.first][captured_coord.second].reset();
		board[captured_coord.first][captured_coord.second] = std::make_unique<piece::empty>(piece::empty(false));


		board[from_coord.first][from_coord.second].swap(board[to_coord.first][to_coord.second]);
		return can_take(move.to);
	} else {
		return true;
	}
}

void game_board::print_coords(coordinate *from, coordinate *to) const {
	auto from_pair = from->get_uncrush();
	auto to_pair = to->get_uncrush();

	printf("x:%d y%d -> x%d y%d", from_pair.first, from_pair.second, to_pair.first, to_pair.second);
}
void game_board::print_coords(coordinate *toprint) const {
	auto print_pair = toprint->get_uncrush();

	printf("x:%d y%d", print_pair.first, print_pair.second);
}

std::vector<move> game_board::available_moves(bool top_player) const {

	std::vector<move> available_moves;
	std::vector<move> piece_moves;
	const piece::game_piece *current_piece, *capture_piece;
	coordinate *capture_coords;
	bool attackmoveexists = false;
	int move_count = 0;

	for(unsigned int i = 0; i < board.size(); i++) {//iterate through board in x direciton

		for(unsigned int j = 0; j < board[i].size(); j++) {//iterate through board in y direction (the column we just added)
			coordinate *coord = coordinate::from_crush(i, j);
			current_piece = get_piece(coord);

			if(current_piece == nullptr) continue;
			if(current_piece->get_is_top() != top_player) continue;//check current player ownes this piece

			piece_moves = current_piece->get_valid_moves(coord);

			move_count++;
			for(unsigned int k = 0; k < piece_moves.size(); k++){
				//validate coordinates
				move curr = piece_moves.at(k);
				if(!valid(curr.from) || !valid(curr.to)) {
					print_coords(curr.from, curr.to);
					printf(" %d coordinates not valid\n", move_count);
					continue;
				}

				if(curr.type == move::VALID_ATTACK) {

					capture_coords = get_captured(curr);
					capture_piece = get_piece(capture_coords);
					if(!capture_piece) continue;

					//check destination is free
					const piece::game_piece *dest = get_piece(curr.to);
					if(!dest) {
						print_coords(curr.from, curr.to);
						printf(" %d ATT: destination not valid\n", move_count);
						continue;
					}
					if(dest->visual() != ' ') {
						print_coords(curr.from, curr.to);
						printf(" %d ATT: destination not free\n", move_count);
						continue;
					}
					//check capture piece is there
					if(capture_piece->visual() == ' ') {
						print_coords(curr.from, curr.to);
						printf(" %d ATT: can't capture whats not there capture piece: ", move_count);
						print_coords(capture_coords);
						printf("\n");
						continue;
					}
					if(capture_piece->get_is_top() == current_piece->get_is_top()) {
						print_coords(curr.from, curr.to);
						printf(" %d ATT: can't capture your own man\n", move_count);
						continue;
					}
					//available_moves.resize( available_moves.size() + piece_moves.size());//valiant effort, but we dont actually know how big it needs to be
					available_moves.push_back(curr);
					print_coords(curr.from, curr.to);
					printf(" %d ATT: move added!\n", move_count);
					attackmoveexists = true;
				}

				if(curr.type == move::VALID && !attackmoveexists) {
					auto tempto = curr.to;
					const piece::game_piece *dest = get_piece(tempto);
					if(!dest || dest->visual() != ' ') {
						print_coords(curr.from, curr.to);
						printf(" %d destination not free\n", move_count);
						continue;
					}
					available_moves.push_back(curr);
					print_coords(curr.from, curr.to);
					printf(" %d move added!\n", move_count);
				}
			}
		}
	}
	if(attackmoveexists){
		//remove any non-attack moves that were added prior to the attack being found
		auto it = available_moves.begin();
		while(it != available_moves.end()) {
			if(it->type == move::VALID_ATTACK) {
				//no non-attack moves after the first attack move
				break;
			}
			//remove the move
			it = available_moves.erase(it);//this increments the iterator
			continue;
		}
	}

	return available_moves;
}

bool game_board::can_take(coordinate *piece_coord) const {
	const piece::game_piece *piece = get_piece(piece_coord);

	if(!piece || piece->visual() == ' ') return false;
	std::vector<move> piece_moves = piece->get_valid_moves(piece_coord);

	for(auto it = piece_moves.begin(); it != piece_moves.end(); it++) {
		
		if(it->type != move::VALID_ATTACK) continue;//dont do non-attack
		if(get_piece(it->to) != nullptr && get_piece(it->to)->visual() != ' ') continue;//dont do if there is a piece at destination

		coordinate *capture_pos = get_captured(*it);
		const piece::game_piece *capture = get_piece(capture_pos);
		if(!capture) return false;
		//if they are on opposite teams, return true
		if(capture->get_is_top() != piece->get_is_top()) return true;
	}
	//no valid attack move, return false
	return false;
}

coordinate * game_board::get_captured(move move) {
	if(move.type != move::VALID_ATTACK) {
		return nullptr;
	}

	auto to_coord = move.to->get_uncrush();
	auto from_coord = move.from->get_uncrush();
	int dx = (to_coord.first - from_coord.first)/2;
	int dy = (to_coord.second - from_coord.second)/2;
	coordinate *capture_pos = coordinate::from_uncrush(from_coord.first + dx, from_coord.second + dy);

	return capture_pos;
}
