#include "model.h"

using namespace draughts::model;

std::unique_ptr<model> model::instance =
nullptr;

model::model(void) : board(game_board(8, 8))
{
}

model * model::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model>(new model);
    }
    return instance.get();
}

int model::get_player_score(int playernum) const
{
    if(active_players.first == playernum) return board.get_top_score();
    if(active_players.second == playernum) return board.get_bottom_score();
    return 0;
}

void model::start_game(int plr1, int plr2)
{
/*	coordinate test_coord = coordinate::from_crush(3, 5);
	std::pair<int, int> cr = test_coord.get_crush();
	std::pair<int, int> uncr = test_coord.get_uncrush();

	std::cout << "starting(from crushed): x" << 3 << " y" << 5 << "\n";
	std::cout << "crushed:   x" << cr.first << " y" << cr.second << "\n";
	std::cout << "uncrushed: x" << uncr.first << " y" << uncr.second << "\n";*/
	active_players.first = plr1;
	active_players.second = plr2;
	
	current_player = active_players.first;
}

int model::get_winner()
{
	printf("getting winner.................................................\n");
    if (board.get_top_score() == 0) return active_players.second;
    if (board.get_bottom_score() == 0) return active_players.first;
	printf("no winner yet\n");
    return EOF;
}

std::string model::get_player_name(int id)
{
	const player* player = get_player(id);
	if(player == nullptr) {
		return "";
	}
	return player->get_player_name();
}

char model::get_token(int x ,int y)
{
    if(!coordinate::is_valid(x,y)){
        return ' ';
    }

	const piece::game_piece *game_piece = board.get_piece(
			coordinate::from_uncrush(x,y)
			);
	return game_piece->visual();
}

void model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{


	bool is_player_top = true;
	if(playernum != current_player) {
		//TODO: notify of wrong player?
		return;
	}


	//get is_player_top
	if(playernum == active_players.first) {
		is_player_top = true;
	} else if(playernum == active_players.second) {
		is_player_top = false;
	} else {
		//TODO: notify of wrong player?
	}



	//get valid moves for that player
	std::vector<move> valid_moves = board.available_moves(is_player_top);

	//check find the valid move in the list

	bool found = false;
	for(auto it = valid_moves.begin(); it != valid_moves.end(); it++) {
		auto fcoord = it->from->get_uncrush();
		auto tcoord = it->to->get_uncrush();

		if(fcoord.first != startx) continue;
		if(fcoord.second != starty) continue;
		if(tcoord.first != endx) continue;
		if(tcoord.second != endy) continue;

		//	-yes
		//		make the move (from the list)
		//		check the return value of make_move
		found = true;
		if(board.make_move(*it)) {
			//			-true
			//				make the player take their turn again
			printf("have to make another move\nx:%d y:%d -> x:%d y:%d\n", startx, starty, endx, endy);
		} else {
			//			-false
			//				other players turn
			printf("making move \nx:%d y:%d -> x:%d y:%d\n", startx, starty, endx, endy);
			if(is_player_top) {
				current_player = active_players.second;
			} else {
				current_player = active_players.first;
			}
		}

		break;
	}

	if(!found) {
		//	-no
		//		make the player take their turn again
		printf("can't make move!\n");
	}
	
}

void model::add_player(const std::string& p)
{
    //std::unique_ptr<player> new_player = std::make_unique<player>(p, next_player_id++);
    
    player_list.push_back(std::make_unique<player>(p, next_player_id++));
}

bool model::player_exists(const std::string& pname)
{
	for(auto it = player_list.begin(); it != player_list.end(); it++) {
		if(it->get()->get_player_name() == pname) {
			return true;
		}
	}
    return false;
}

int model::get_current_player(void)
{
    return current_player;
}

std::map<int, std::string> model::get_player_list(void) 
    const
{
    std::map<int, std::string> nameslist;
    auto this_model = get_instance();
    for(unsigned int i = 0; i < this_model->player_list.size(); i++) {
        const player* player = this_model->player_list.at(i).get();
        std::string player_name = player->get_player_name();
        nameslist[static_cast<int>(i)] = player_name;
    }
    return nameslist;
}

void model::delete_instance(void)
{
    instance.reset(nullptr);
}


int model::get_width()
{
    return board.get_x();
}

int model::get_height()
{
    return board.get_y();
}

model::~model(void)
{
}

const player* model::get_player(piece::game_piece *piece) const {
	if(piece->get_is_top()) {
		return get_player(active_players.first);
	} else {
		return get_player(active_players.second);
	}
}

const player* model::get_player(int id) const {
	for(auto it = player_list.begin(); it != player_list.end(); it++) {
		const player *player = it->get();
		if(id == player->get_id()) {
			return player;
		}
	}
	return nullptr;
}

const player* model::get_player(std::string name) const {
	for(auto it = player_list.begin(); it != player_list.end(); it++) {
		const player *player = it->get();
		if(name == player->get_player_name()) {
			return player;
		}
	}
	return nullptr;
}
