#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>

#define _LOG_FILE_ "./logs.txt"

#ifdef DS

class Logger {
    static std::ofstream output;

public:
    template<typename... Args>
    static void info(Args... msgs) {
        output << "[INFO] " << __TIME__ << '\t';
        (output << ... << msgs);
    }

    static void init() {
        output.open(_LOG_FILE_);
    }
};





#endif // LOGGER_H
