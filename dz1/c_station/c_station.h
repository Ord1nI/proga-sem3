//Убрал id
//Добавил проверку на unsigned

#ifndef _C_STATION_H_
#define _C_STATION_H_

#include <string>

class C_station {
    std::string name;
    unsigned int workshops;
    unsigned int working_workshops;
    float efficiency;
    unsigned int not_working_workshops;


    int error;
public:
    C_station(std::string name, unsigned int workshops, unsigned int working_workshops,float efficiency);

    std::string get_name() const;
    unsigned int get_workshops() const;
    unsigned int get_working_workshops() const;
    float get_not_working_workshops() const;
    float get_efficiency() const;

    bool good();

    bool inc_working_workshops();

    std::string string();
};

#endif
