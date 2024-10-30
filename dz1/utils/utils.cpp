#include <iostream>
#include "utils.h"

std::string get_string(std::string out_str) {
    std::string res;

    for (;;) {
        std::cout << out_str;
        std::getline(std::cin>>std::ws, res);
        if (!res.empty()) {
            Logger(res,'\n');
            return res;
        }
    }
}

bool get_bool(std::string str) {
    char inp_tmp;
    std::cout << str;
    while (std::cin >> inp_tmp) {
        Logger(inp_tmp,'\n');
        switch(std::tolower(inp_tmp)){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << str;
        }
    }
    return false;
}
