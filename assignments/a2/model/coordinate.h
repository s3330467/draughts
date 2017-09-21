#include <utility>

class coordinate {
	int x;
	int y;

	protected:
	coordinate(int x, int y) : x(x), y(y) {}

	public:
	static coordinate from_crush(int x, int y) { return coordinate(x, y); }
	static coordinate from_uncrush(int x, int y) { return coordinate(x/2, y); }

	std::pair<int, int> get_crush();
	std::pair<int, int> get_uncrush();
};
