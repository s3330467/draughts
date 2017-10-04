#include "ncview/ui.h"
#include "nc_controller/controller.h"
#include "model/model.h"

int main(void)
{
	//get instance of ncview ui
    draughts::ncview::ui * view = draughts::ncview::ui::get_instance();

	//call these functions when the process is closed
	//...delete ui, controller, and model
    atexit(draughts::ncview::ui::delete_instance);
    atexit(draughts::nc_controller::controller::delete_instance);
    atexit(draughts::model::model::delete_instance);
    view->main_menu();//open the main menu
}
