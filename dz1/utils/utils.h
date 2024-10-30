#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <iostream>

#define USELOGGER

#ifdef USELOGGER
template<typename... Args>
void info(Args... msgs) {
    (std::cerr << ... << msgs);
}

#define Logger(x...) (info(x))
#endif

template<typename T>
T get_pos_number(std::string out_str) {
    T res;

    for (;;) {
        std::cout << out_str;

        if(std::cin >> res && res >= 0) {
            Logger(res,'\n');
            return res;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод\n";
        }
    }
}

bool get_bool(std::string str);
std::string get_string(std::string out_str);

#endif
