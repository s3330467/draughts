#include "main_menu.h"
#include "add_player_window.h"
#include "game_window.h"
#include "player_selection_window.h"

#pragma once

namespace draughts
{
    namespace nc_controller
    {
        class controller;
    }
    namespace model
    {
        class model;
    }
    namespace ncview
    {
		//there is a main_menu class here, do not confuse it with the ui
		//main_menu function
        class ui
        {
            draughts::nc_controller::controller * thecontroller;
            draughts::model::model * themodel;
            static std::unique_ptr<ui> instance;

            ui(void);//constructor, creates instances of controller and model

            public:
                void main_menu(void);

                void add_player(void);

                void play_game(void);

                void show_game_window(player_pair);

                static ui* get_instance();

                static void delete_instance(void);

                virtual ~ui(void);
        };
    }
}
