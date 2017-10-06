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

int model::get_player_score(int playernum)
{
    return EOF;
}

void model::start_game(int plr1, int plr2)
{
	coordinate test_coord = coordinate::from_crush(3, 5);
	std::pair<int, int> cr = test_coord.get_crush();
	std::pair<int, int> uncr = test_coord.get_uncrush();

	std::cout << "starting(from crushed): x" << 3 << " y" << 5 << "\n";
	std::cout << "crushed:   x" << cr.first << " y" << cr.second << "\n";
	std::cout << "uncrushed: x" << uncr.first << " y" << uncr.second << "\n";
}

int model::get_winner()
{
    return EOF;
}

std::string model::get_player_name(int id)
{
    for(unsigned int i = 0; i < player_list.size(); i++){
        player* player = player_list.at(i).get();
        if(player->get_id() == (int)i){
            return player->get_player_name();
        }
    }
    return "";
}

char model::get_token(int x ,int y)
{
	//TODO: remove the printf
	//printf("getting token at: x%d y%d\n", x, y);

    if(coordinate::is_valid(x,y)){
        return ' ';
    }

    game_piece *game_piece = board.get_piece(coordinate::from_uncrush(x,y));

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
}

void model::add_player(const std::string& p)
{
    std::unique_ptr<player> new_player = std::make_unique<player>(p, next_player_id++);
    player_list.push_back(std::move(new_player));
}

bool model::player_exists(const std::string& pname)
{
    return false;
}

int model::get_current_player(void)
{
    return EOF;
}

std::map<int, std::string> model::get_player_list(void) 
    const
{
    std::map<int, std::string> nameslist;
    auto this_model = get_instance();
    for(unsigned int i = 0; i < this_model->player_list.size(); i++) {
        player* player = this_model->player_list.at(i).get();
        std::string player_name = player->get_player_name();
        nameslist[(int)i] = player_name;
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

