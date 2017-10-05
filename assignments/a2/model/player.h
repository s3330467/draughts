#include <string>

namespace draughts {
	namespace model {

		class player {
			std::string player_name;
			int total_score;

			protected:

			public:
			player(std::string player_name) : player_name(player_name), total_score(0) {}
			std::string get_player_name();
			int get_total_score();
		};
	}
}
