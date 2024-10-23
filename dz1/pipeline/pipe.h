#ifndef _PIPE_H_
#define _PIPE_H_

#ifndef _PIPE_H_
#define _PIPE_H_

#include "fstream"

class Pipe{
    int id;
    std::string name;
    float length;
    float diameter;
    bool is_reparing;

public:
    Pipe(int id, std::string name, float length, float diameter, bool is_reparing);
    Pipe(std::ifstream file);
    Pipe();

    int get_id();
    std::string get_name();
    float get_length();
    float get_diameter();
    bool get_is_reapring();

cp pipe    void  change_is_reparing();

    std::string string();
};

#endif


#endif // _PIPE_H_
