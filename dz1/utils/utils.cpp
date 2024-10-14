#include <iostream>
#include "utils.h"

int get_pos_int(std::string out_str) {
    int res;

    for (;;) {
        std::cout << out_str;

        if(std::cin >> res && res >= 0) {
            return res;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод\n";
        }
    }
}

float get_pos_float(std::string out_str) {
    float res = -1;

    for (;;) {

        std::cout << out_str;
        if(std::cin >> res && res >= 0) {
            return res;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректные данные\n";
        }
    }
}

std::string get_string(std::string out_str) {
    std::string res;

    for (;;) {
        std::cout << out_str;
        std::getline(std::cin>>std::ws, res);
        if (!res.empty()) {
            return res;
        }
    }
}

bool get_bool(std::string str) {
    char inp_tmp;
    std::cout << str;
    while (std::cin >> inp_tmp) {
        switch(std::tolower(inp_tmp)){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << str;
        }
    }
}
