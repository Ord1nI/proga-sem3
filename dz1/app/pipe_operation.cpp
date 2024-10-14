#include "app.h"
#include <iostream>
#include "../utils/utils.h"
#include <sstream>

void App::show_pipe_operations() {
    std::cout << "1. Add Pipe\n" <<
                 "2. Select by name\n" <<
                 "3. Select by feature \"Is reparing\"\n" <<
                 "4. Show selected items\n" <<
                 "5. Clear selected\n" <<
                 "6. Change in selected feateure \"Is reparing\"\n" <<
                 "0. Back\n";
}

void App::pipe_operation() {
    int input;
    for(;;) {
        show_pipe_operations();
        input = get_pos_int("");
        switch (input) {
            case 1:
                add_pipe();
                break;
            case 2:
                pipe_select_by_name();
                break;
            case 3:
                pipe_select_by_is_reparing();
                break;
            case 4:
                pipe_show_selected_items();
                break;
            case 5:
                pipe_clear_selection();
                break;
            case 6:
                pipe_change();
                break;
            case 0:
                return;
            default:
                std::cout << "Введите корректное значение\n";
        }
    }
}

void App::add_pipe() {
    pipeline.add(Pipe(id_pipeline,
                      get_string("Enter name: "),
                      get_pos_float("Enter length: "),
                      get_pos_float("Enter diameter: "),
                      get_bool("Is pipe reparing? (Y/n): "))
    );
    id_pipeline++;
}

void App::pipe_select_by_name() {
    if (this->pipeline.select_by_name(get_string("Введите имя: ")) > 0) {
        pipe_show_selected_items();
    } else {
        std::cout << "No pipes was found\n";
    }
}

void App::pipe_select_by_is_reparing() {
    if (this->pipeline.select_by_is_reparing(get_bool("Is pipe reparing? (Y/n): ")) > 0) {
        pipe_show_selected_items();
    } else {
        std::cout << "No pipes was found\n";
    }
}

void App::pipe_show_selected_items() {
    std::string out = this->pipeline.string_selected();
    if (out.length() == 0) {
        std::cout << "Selected list is empty\n";
    } else {
        std::cout << out;
    }
}

void App::pipe_clear_selection() {
    this->pipeline.clear_selection();
}

void App::pipe_change() {
    pipe_show_selected_items();
    std::stringstream ss(get_string("Enter ids devided by space"));

    int id;

    while(!ss.eof()) {
        if (ss >> id) {
            if (pipeline.change(id)) {
                std::cout << id << " changed\n";
            } else {
                std::cout << id << " not in selected list\n";
            }
        } else {
            ss.clear();
            ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input\n";
        }
    }
    pipe_clear_selection();
}
