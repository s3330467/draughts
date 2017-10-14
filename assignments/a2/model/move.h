#include "coordinate.h"

#pragma once
namespace draughts {
	namespace model {

		struct move {
				enum move_type { VALID, VALID_ATTACK, INVALID };

				coordinate from;
				coordinate to;
				move_type type;

				move(void) {}
				move(coordinate f, coordinate t, move_type ty) : from(f), to(t), type(ty) {}
		};
	}
}
