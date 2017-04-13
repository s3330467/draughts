#ifndef GAME_LOCATION__HPP
#define GAME_LOCATION__HPP

#include "game_location.h"

namespace game_location {
    enum direction {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        UP,
        DOWN,
        INVALID
    };
}

namespace game_location {
    class connection {
        // Attributes
        public :
            room * start_room;
            room * end_room;
            game_location::direction dir;
    };
}

namespace game_location {
    class room {
        // Attributes
        private :
            int g_room_no;
            int l_room_no;
            area * myarea;
            std::string name;
            std::string description;
            room*[NUM_DIRECTIONS] exits;
    };
}

namespace game_location {
    class area {
        // Attributes
        private :
            int id;
            std::string name;
        public :
            std::string description;
        private :
            stl_container<connection> entrances;
            stl_container<connection> exits;
            stl_container<std::unique_ptr<room>> rooms;
    };
}

#endif