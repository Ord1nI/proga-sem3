#include "app.h"
#include "../pipe/pipe.h"
#include <iostream>
#include "../utils/utils.h"
#include <unordered_set>

void App::show_pipe_operations() {
    std::cout << "1. Add Pipe\n" <<
                 "2. Select by name\n" <<
                 "3. Select by feature \"Is reparing\"\n" <<
                 "4. Show selected items\n" <<
                 "5. Clear selected\n" <<
                 "6. Change by id\n" <<
                 "7. Change all\n" <<
                 "0. Back\n";
}

void App::pipe_operation() {
    int input;
    for(;;) {
        show_pipe_operations();
        input = get_pos_number<int>("");
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
                pipe_change_by_id();
                break;
            case 7:
                pipe_change_all();
            case 0:
                return;
            default:
                std::cout << "Введите корректное значение\n";
        }
    }
}

void App::add_pipe() {
    pipeline.add(Pipe(get_string("Enter name: "),
                      get_pos_number<float>("Enter length: "),
                      get_pos_number<float>("Enter diameter: "),
                      get_bool("Is pipe reparing? (Y/n): "))
    );
}

void App::pipe_select_by_name() {
    std::string name = get_string("Введите имя: ");

    if (pipeline.select_by_name(name).size() > 0) {
        pipe_show_selected_items();
    } else {
        std::cout << "No pipes was fount\n";
    }
}

void App::pipe_select_by_is_reparing() {
    bool is_r = get_bool("Is pipe reparing? (Y/n): ");

    if (pipeline.select_by_is_reparing(is_r).size() > 0) {
        pipe_show_selected_items();
    } else {
        std::cout << "No pipes was found\n";
    }
}

bool App::pipe_show_selected_items() {
    std::string out = this->pipeline.string_selected();
    if (out.length() == 0) {
        std::cout << "Selected list is empty\n";
        return false;
    } else {
        std::cout << out;
        return true;
    }
}

void App::pipe_clear_selection() {
    this->pipeline.clear_selection();
}

void App::pipe_change_by_id() {
    if (!pipe_show_selected_items()) {
        return;
    }
    std::cout << "Enter ids to edit(0 is the end of input)\n";

    std::unordered_set<unsigned int> inp;

    unsigned int tmp_inp;
    size_t tmp_size = 0;

    while((tmp_inp = get_pos_number<int>("ID: ")) > 0) {
        inp.emplace(tmp_inp);

        if(inp.size() > tmp_size) {
            if (pipeline.change(tmp_inp)) {
                std::cout << tmp_inp << " changed\n";
            } else {
                std::cout << tmp_inp << " doesn't change\n";
            }
            tmp_size = inp.size();
        }
    }

    pipe_clear_selection();
}

void App::pipe_change_all() {
    if (!pipe_show_selected_items()) {
        return;
    }

    for (auto tmp_inp : pipeline.get_selected()) {
        if (pipeline.change(tmp_inp)) {
            std::cout << tmp_inp << " changed\n";
        } else {
            std::cout << tmp_inp << " doesn't change\n";
        }
    }

    pipe_clear_selection();
}
