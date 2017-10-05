#include <string>

namespace draughts {
	namespace model {

		class player {
			std::string player_name;
			int id;
			int total_score;

			public:
			player(std::string player_name, int id) : player_name(player_name), id(id), total_score(0) {}
			std::string get_player_name();
			int get_total_score();
			int get_id();
		};
	}
}
