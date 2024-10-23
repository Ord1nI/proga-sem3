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

    int error;
public:
    C_station(std::string name, unsigned int workshops, unsigned int working_workshops,float efficiency);
    C_station();

    std::string get_name() const;
    int get_workshops() const;
    int get_working_workshops() const;
    float get_efficiency() const;

    bool good();

    void set_name(std::string name);
    void set_workshops(unsigned int workshops);
    void set_working_workshops(unsigned int working_workshops);
    void set_efficiency(float efficiency);

    std::string string();
};

#endif
