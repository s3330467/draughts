#include "model.h"

using namespace draughts::model;

std::unique_ptr<model> model::instance =
nullptr;

model::model(void) : board(game_board(10, 10))
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
    if(active_players.first == playernum) return top_score;
    if(active_players.second == playernum) return bottom_score;
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
    top_score = 12;
    bottom_score = 12;
	active_players.first = plr1;
    current_player = plr1;
	active_players.second = plr2;
	
	current_player = active_players.first;
}

int model::get_winner()
{
    if (top_score == 0) return active_players.second;
    if (bottom_score == 0) return active_players.first;
    return -1;
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
	//TODO: remove the printf
	//printf("getting token at: x%d y%d\n", x, y);

    if(coordinate::is_valid(x,y)){
        return ' ';
    }

	const piece::game_piece *game_piece = board.get_piece(
			coordinate::from_uncrush(x,y)
			);

	if(game_piece == nullptr) {
		return ' ';
	}

    if(game_piece->get_is_top()) {
        return 'x';
    } else {
        return 'o';
    }
}

void model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{
	if(playernum != current_player) {
		//TODO: notify of wrong player?
		return;
	}

	coordinate start = coordinate::from_uncrush(startx, starty);
    coordinate end = coordinate::from_uncrush(endx, endy);

	start = start;//TODO
	end = end;

	
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
