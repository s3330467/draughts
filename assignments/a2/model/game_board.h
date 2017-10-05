#include <utility>

namespace draughts {
	namespace model {

		class game_board {
			std::vector<std::vector<std::unique_ptr<game_piece>>> board;
			int x;
			int y;


			public:
			game_board(int x, int y);

			/*
			static coordinate from_crush(int x, int y) { return coordinate(x, y); }
			static coordinate from_uncrush(int x, int y) { return coordinate(x/2, y); }
			*/

			int get_x() { return x; }
			int get_y() { return y; }

			game_piece * get_game_piece(coordinate coord) {
		};
	}
}
