#include "model.h"

//using namespace of this class
using namespace draughts::model;

std::unique_ptr<model> model::instance =
nullptr;

model::model(void) 
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
	std::pair<int, int> uncr = test_coord.get_uncrush();
	std::pair<int, int> cr = test_coord.get_crush();

	std::cout << "uncrushed: x" << uncr.first << " y" << uncr.second << "\n";
	std::cout << "crushed:   x" << cr.first << " y" << cr.second << "\n";
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
    return '\0';
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
    return EOF;
}

int model::get_height()
{
    return EOF;
}

model::~model(void)
{
}

