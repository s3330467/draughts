#include "menu.h"

#pragma once

namespace draughts
{
    namespace ncview
    {
		//not to be confused with the ui main_menu function
        class main_menu : public menu
        {
            static const std::vector<std::string> strings;
            public:
                main_menu(void);
                virtual ~main_menu(void);
        };
    }
}
