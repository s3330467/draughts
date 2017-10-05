#include "model.h"

std::unique_ptr<draughts::model::model> draughts::model::model::instance =
nullptr;

draughts::model::model::model(void) 
{
}

draughts::model::model * draughts::model::model::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model>(new model);	
    }
    return instance.get();    
}

int draughts::model::model::get_player_score(int playernum)
{
    return EOF;
}

void draughts::model::model::start_game(int plr1, int plr2)
{
	coordinate test_coord = coordinate::from_crush(3, 5);
	std::pair<int, int> uncr = test_coord.get_uncrush();
	std::pair<int, int> cr = test_coord.get_crush();

	std::cout << "uncrushed: x" << uncr.first << " y" << uncr.second << "\n";
	std::cout << "crushed:   x" << cr.first << " y" << cr.second << "\n";
}

int draughts::model::model::get_winner()
{
    return EOF;
}

std::string draughts::model::model::get_player_name(int id)
{
    for(unsigned int i = 0; i < player_list.size(); i++){
        player* player = player_list.at(i).get();
        if(player->get_id() == (int)i){
            return player->get_player_name();
        }
    }
    return "";
}

char draughts::model::model::get_token(int x ,int y)
{
    if(coordinate.is_valid(x,y)){
        return ' ';
    }
    game_piece game_piece = get_game_piece(coordinate::from_uncrush(x,y));
    if(game_piece.get_is_top()){
        return 'x';
    }
    if(!game_piece.get_is_top()){
        return 'o';
    }
    return ' ';
}

void draughts::model::model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{
}

void draughts::model::model::add_player(const std::string& p)
{
    std::unique_ptr<player> new_player = std::make_unique<player>(p, next_player_id++);
    player_list.push_back(std::move(new_player));
}

bool draughts::model::model::player_exists(const std::string& pname)
{
    return false;
}

int draughts::model::model::get_current_player(void)
{
    return EOF;
}

std::map<int, std::string> draughts::model::model::get_player_list(void) 
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

void draughts::model::model::delete_instance(void)
{
    instance.reset(nullptr);
}


int draughts::model::model::get_width()
{
    return game_board.get_x();
}

int draughts::model::model::get_height()
{
    return game_board.get_y();
}

draughts::model::model::~model(void)
{
}

