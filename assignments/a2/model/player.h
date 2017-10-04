#include <string>


class player {
	std::string playerName;
	int totalScore;

	protected:

	public:
	player(std::string playerName) : playerName(playerName), totalScore(0) {}
	std::string get_playerName();
	int get_totalScore();
};
