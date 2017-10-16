#include <vector>
#include "../coordinate.h"
#include "../move.h"

#pragma once

namespace draughts {
	namespace model {
		namespace piece {

			class game_piece {
				protected:
				bool is_top;

				public:

				game_piece(bool is_top) : is_top(is_top) {}
				draughts::model::coordinate get_coords() const;
				bool get_is_top() const;

				virtual char visual() const = 0;

				//virtual move::mtype is_valid(coordinate *from, coordinate *to) const = 0;
				virtual std::vector<move> get_valid_moves(coordinate *from) const = 0;
			};
		}
	}
}
