#include "../coordinate.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class game_piece {
				protected:
				coordinate coords;
				bool is_top;

				public:
				enum move_type { VALID, VALID_ATTACK, INVALID };

				game_piece(coordinate coords, bool is_top) : coords(coords), is_top(is_top) {}
				draughts::model::coordinate get_coords() const;
				bool get_is_top() const;

				virtual move_type is_valid(coordinate to) const = 0;
			};
		}
	}
}
