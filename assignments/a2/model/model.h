#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>

#include "coordinate.h"
#include "player.h"
#include "pieces/game_piece.h"
#include "pieces/empty.h"
#include "game_board.h"

#pragma once

namespace draughts
{
    namespace model
    {
        class model
        {
            static std::unique_ptr<model> instance;

			game_board board;

            std::vector<std::unique_ptr<player>> player_list;
            int next_player_id = 0;

			std::pair<int, int> active_players;
            int current_player, top_score, bottom_score;

            model(void);
            bool player_exists(const std::string&);

            public:
            void start_game(int, int);
            char get_token(int, int);
            void make_move(int, int, int, int, int);

            void add_player(const std::string& );
            int get_player_score(int) const;
            int get_current_player(void);
            std::string get_player_name(int);
            std::map<int, std::string> get_player_list(void) const;
            int get_winner();
            int get_width();
            int get_height();
            static model * get_instance(void);
            static void delete_instance(void);
            virtual ~model(void);

			private:
			const player* get_player(piece::game_piece *piece) const;
			/**
			 * gets player id
			 *
			 * @param int id: id of the player you want
			 *
			 * @return const player* the player you wanted
			 * @return nullptr if the player is not found
			 */
			const player* get_player(int) const;
			/**
			 * gets player id
			 *
			 * @param string name: id of the player you want
			 *
			 * @return const player* the player you wanted
			 * @return nullptr if the player is not found
			 */
			const player* get_player(std::string) const;
        };
    }
}
