#ifndef _C_STATION_H_
#define _C_STATION_H_

#include <string>

class C_station {
    int id;
    std::string name;
    int workshops;
    int working_workshops;
    float efficiency;
public:
    C_station(int id, std::string name, int workshops, int working_workshops,float efficiency);
    C_station();

    int get_id();
    std::string get_name();
    int get_workshops();
    int get_working_workshops();
    float get_efficiency();

    void set_name(std::string name);
    void set_workshops(int workshops);
    bool set_working_workshops(int working_workshops);
    void set_efficiency(float efficiency);

    std::string string();
};

#endif
