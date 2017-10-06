#include <utility>

#pragma once

namespace draughts {
	namespace model {

		class coordinate {
			int x;
			int y;

			protected:
			coordinate(int x, int y) : x(x), y(y) {}

			public:
			static coordinate from_crush(int x, int y) {
				return coordinate(x, y);
			}

			//pauls code has x and y swapped and indices start at 1
			static coordinate from_uncrush(int y, int x) {
				return coordinate((x-1)/2, y-1);
			}

			std::pair<int, int> get_crush();
			std::pair<int, int> get_uncrush();

			//used to check weather a coordinate from controller is valid or a
			//blank space
			static bool is_valid(int y, int x);

			bool check_valid();
		};
	}
}
