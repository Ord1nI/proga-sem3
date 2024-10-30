#ifndef _APP_H_
#define _APP_H_

#include "../pipeline/pipeline.h"
#include "../factory/factory.h"

#define _SAVE_FILE_ "./save.txt"

class App {
    Pipeline pipeline;
    Factory factory;

    void show_main_page();

    //PIPE OPERATION
    void pipe_operation();

    void show_pipe_operations();

    void add_pipe();

    void pipe_select_by_name();
    void pipe_select_by_is_reparing();

    bool pipe_show_selected_items();

    void pipe_clear_selection();

    void pipe_change_by_id();

    void pipe_change_all();


    //C_STATION OPERATION
    void c_station_operation();

    void show_c_station_operations();

    void add_c_station();

    void c_station_select_by_name();
    void c_station_select_by_working_workshops();

    bool c_station_show_selected_items();

    void c_station_clear_selection();

    void c_station_change_by_id();

    void c_station_change_all();
    //

    void save_to_file();
    void load_from_file();

    void print_all();
public:
    App();

    void run();
};

#endif
