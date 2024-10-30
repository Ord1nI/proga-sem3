//Убрал id
//Добавил
#ifndef _PIPE_H_
#define _PIPE_H_

#include <string>

class Pipe{
    std::string name;
    float length;
    float diameter;
    bool is_reparing;

    int error;
public:
    Pipe(std::string name, float length, float diameter, bool is_reparing);
    Pipe();

    std::string get_name() const;
    float get_length() const;
    float get_diameter() const;
    bool get_is_reapring() const;

    void  change_is_reparing();

    std::string string();
};

#endif
