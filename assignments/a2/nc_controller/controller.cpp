#include "controller.h"
#include "../ncview/ui.h"
#include "../model/model.h"


std::unique_ptr<draughts::nc_controller::controller>
draughts::nc_controller::controller::instance=nullptr;

draughts::nc_controller::controller::controller(void) 
{

}

draughts::model::model * draughts::nc_controller::controller::get_model(
    void)
{
    return model::model::get_instance();
}

draughts::ncview::ui * draughts::nc_controller::controller::get_view(void)
{
    return ncview::ui::get_instance();
}

    draughts::nc_controller::controller*
draughts::nc_controller::controller::get_instance(void)
{
    if(instance == nullptr){
        instance = std::unique_ptr<controller>(new controller);
    }
    return instance.get();
}

    std::vector<std::unique_ptr<draughts::nc_controller::command>>
draughts::nc_controller::controller::get_main_menu_commands(void)
{
    std::vector<std::unique_ptr<command>> main_menu_commands;
    main_menu_commands.emplace_back(std::make_unique<addplayer_command>());
    main_menu_commands.emplace_back(std::make_unique<newgame_command>());
    main_menu_commands.emplace_back(std::make_unique<exit_command>());
    return std::move(main_menu_commands);
}

void draughts::nc_controller::controller::delete_instance(void)
{
    instance.reset(nullptr);
}

void draughts::nc_controller::controller::start_game(
    std::map<int, std::string> players)
{
    std::vector<int> ids;

	//call a pair of <int, string> a player
    using player = std::pair<int, std::string>;

	//init vars
    player player1, player2;
    std::pair<player, player> theplayers; 
    int count = 0;

	//itterate through 'players' map of 2 players (argument to this function)
    for(auto & pair : players)
    {
        count++;

		//assign the id in the same order as the players
        ids.push_back(pair.first);
        if(count == 1)
        {
            player1 = pair;//player1 is the first player passed to the function
        }
        else
        {
            player2 = pair;//player2 is the second player passed to the funciton
        }
    }

	//make a pair of players
    theplayers = std::make_pair(player1, player2);

	//start the game, giving the ids
    get_model()->start_game(ids[0], ids[1]);//why not just player1.first and player2.first?
	//i suppose there would be some compatability for > 2 players if you didnt
	//put 'if(count == 1) {...} else {', and instead had a vector of players or
	//something.
	
	//this is also not safe if the players map has > 2 players, because
	//'player2' in 'thePlayers' would be set to the last player itterated
	//through, but 'start_game' would be called with the second player being the
	//id of the second player that was itterated.

	//show window
    get_view()->show_game_window(theplayers);
}

draughts::nc_controller::controller::~controller(void)
{
}
