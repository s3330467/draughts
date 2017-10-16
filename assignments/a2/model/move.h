#include "coordinate.h"

#pragma once
namespace draughts {
	namespace model {

		struct move {
				enum mtype { VALID, VALID_ATTACK, INVALID };

				coordinate *from;
				coordinate *to;
				mtype type;

				move(void) : from(nullptr), to(nullptr), type(INVALID) {}
				move(coordinate *from, coordinate *to, mtype type) : from(from), to(to), type(type) {}
		};
	}
}
