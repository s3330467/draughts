#include <string>

namespace draughts {
	namespace model {

		class game_piece {
			coordinate coords;
			bool is_top;

			public:
			game_piece(coordinate coords, bool is_top) : coords(coords), is_top(is_top) {}
			coordinate get_coords();
			bool get_is_top();
		};
	}
}
