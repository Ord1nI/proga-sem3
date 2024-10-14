#include "app.h"
#include "../utils/utils.h"
#include <iostream>
#include <sstream>


void App::show_c_station_operations() {
    std::cout << "1. Add C_station\n" <<
                 "2. Select by name\n" <<
                 "3. Select by working workshops\n" <<
                 "4. Show selected items\n" <<
                 "5. Clear selected\n" <<
                 "6. Change in selected working workshops\n" <<
                 "0. Back\n";
}

void App::c_station_operation() {
    int input;
    for(;;) {
        show_c_station_operations();
        input = get_pos_int("");
        switch(input) {
            case 1:
                add_c_station();
                break;
            case 2:
                c_station_select_by_name();
                break;
            case 3:
                c_station_select_by_working_workshops();
                break;
            case 4:
                c_station_show_selected_items();
                break;
            case 5:
                c_station_clear_selection();
                break;
            case 6:
                c_station_change();
                break;
            case 0:
                return;
            default:
                std::cout << "Введите корректное значение\n";
                break;
        }
    }

}

void App::add_c_station() {
    std::string name = get_string("Enter name: ");

    int workshops = get_pos_int("Enter number of workshops: ");

    int working_workshops;

    for(working_workshops = get_pos_int("Enter number of working workshops: ");
        working_workshops > workshops;
        working_workshops = get_pos_int("Enter number of working workshops: "));

    factory.add(C_station(id_factory,
                          name,
                          workshops,
                          working_workshops,
                          get_pos_float("Enter efficiency: "))
    );

    id_factory++;
}

void App::c_station_select_by_name() {
    if (this->factory.select_by_name(get_string("Введите имя: ")) > 0) {
        c_station_show_selected_items();
    } else {
        std::cout << "No pipes was found\n";
    }
}

void App::c_station_select_by_working_workshops() {
    if (this->factory.select_by_working_workshops(get_pos_int("Введите количесво рабочих станций: ")) > 0) {
        c_station_show_selected_items();
    } else {
        std::cout << "No stations was fount\n";
    }
}

void App::c_station_show_selected_items() {
    std::string out = this->factory.string_selected();
    if (out.length() == 0) {
        std::cout << "Selected list is empty\n";
    } else {
        std::cout << out;
    }
}

void App::c_station_clear_selection() {
    this->factory.clear_selection();
}

void App::c_station_change() {
    c_station_show_selected_items();
    int new_workshops = get_pos_int("Enter new working workshops value: ");
    std::stringstream ss(get_string("Enter ids devided by space: "));

    int id;

    while(!ss.eof()) {
        if (ss >> id) {
            if (factory.change(id, new_workshops)) {
                std::cout << id << " changed\n";
            } else {
                std::cout << id << " doesn't change\n";
            }
        } else {
            ss.clear();
            ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input\n";
        }
    }
    c_station_clear_selection();
}
